#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <deque>
#include <cstdlib>
#include <limits>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe(char **argv);
		~PmergeMe(void);
		
		void sort();


	private:
		std::vector<int> _cvector;
		std::deque<int>  _cdeque;
		void checkFillCvector(char **argv);
		template <typename T>
		void mergeInsertSort(T &container);
		template <typename T>
		void displayContainer(T &container, char c);

		PmergeMe(void);
		PmergeMe(const PmergeMe& toCopy);
		PmergeMe& operator=(const PmergeMe& toCopy);
};

#endif
