#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>
//#include <list>

class PmergeMe
{
	public:
		PmergeMe(char **argv);
		~PmergeMe(void);

		void sort();


	private:
		std::vector<unsigned int> _cvector;
		void checkFillCvector(char **argv);
		PmergeMe(void);
		PmergeMe(const PmergeMe& toCopy);
		PmergeMe& operator=(const PmergeMe& toCopy);

};

#endif
