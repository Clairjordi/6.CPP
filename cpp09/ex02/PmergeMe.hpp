#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>
#include <limits>
//#include <list>

class PmergeMe
{
	public:
		PmergeMe(char **argv);
		~PmergeMe(void);
		//Template<typename T>
		void sort();


	private:
		std::vector<int> _cvector;
		void checkFillCvector(char **argv);
		void InsertFusion(size_t threshold);
		void InsertionSort(size_t size);
		PmergeMe(void);
		PmergeMe(const PmergeMe& toCopy);
		PmergeMe& operator=(const PmergeMe& toCopy);

};

#endif
