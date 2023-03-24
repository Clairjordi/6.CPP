#include "PmergeMe.hpp"

/* Constructor and Destructor */
PmergeMe::PmergeMe(char **argv)
{
	checkFillCvector(argv);
}

PmergeMe::~PmergeMe(void)
{
}


/* Member Function */
void PmergeMe::sort()
{
	std::vector<int>::iterator middle = _cvector.begin();
	//std::vector<int>::iterator ite = _cvector.end();
	advance(middle, _cvector.size() / 2 - 1);
	std::cout << *middle << std::endl;
	//size_t threshold = 3;
	//InsertFusion(threshold);
}

/*private Function*/
bool checkIsDigit(char *arg)
{
	for (int i = 0; arg[i]; i++)
	{
		if (isdigit(arg[i]) == false)
			return false;
	}
	return true;
}
void PmergeMe::checkFillCvector(char **argv)
{
	for (int i = 0; argv[i]; i++)
	{
		if (argv[i][0] == '\0')
			throw std::logic_error("not a good number");
		if (checkIsDigit(argv[i]) == false)
			throw std::logic_error("not a good number");
		long num = strtol(argv[i], NULL, 10);
		if (num > std::numeric_limits<int>::max())
			throw std::logic_error("Out of range");
		_cvector.push_back(atoi(argv[i]));
	}

	// std::vector<int>::iterator it = _cvector.begin();
	// std::vector<int>::iterator ite = _cvector.end();
	// for (it = _cvector.begin(); it != ite; it++)
	// 	std::cout << *it << std::endl;
}

void PmergeMe::InsertFusion(size_t threshold)
{
	(void) threshold;


	// if (begin < end)
	// {
	// 	size_t size = _cvector.size();
	// 	if (size <= threshold)
	// 		InsertionSort(size);
	// 	else
	// 	{
	// 		int middle = 3; 
	// 	}
    //
	// }
}

void PmergeMe::InsertionSort(size_t size)
{
	(void) size;
}

