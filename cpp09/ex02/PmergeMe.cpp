#include "PmergeMe.hpp"

/* Constructor and Destructor */
PmergeMe::PmergeMe(char **argv)
{
	checkFillCvector(argv);
}

PmergeMe::~PmergeMe(void)
{
}

void InsertFusion(std::vector<int>::iterator begin, std::vector<int>::iterator end, int threshold)
{
	if (begin < end)
	{
		size_t size = _cvector.size();
		if (size <= threshold)
			mergeSort(size);
		else
		{
			int middle = 
		}

	}
}

/* Member Function */
void PmergeMe::sort()
{
	int threshold = 3;
	InsertFusion(_cvector.begin(), _cvector.end(), threshold);
}

/*private Function*/
void PmergeMe::checkFillCvector(char **argv)
{
	for (int i = 0; argv[i]; i++)
	{
		_cvector.push_back(atoi(argv[i]));
	}

	// std::vector<unsigned int>::iterator it = _cvector.begin();
	// std::vector<unsigned int>::iterator ite = _cvector.end();
	// for (it = _cvector.begin(); it != ite; it++)
	// 	std::cout << *it << std::endl;
}
