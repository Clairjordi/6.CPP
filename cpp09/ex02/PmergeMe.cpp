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
	displayContainer(_cvector, 'b');

	mergeInsertSort(_cvector);
	clock_t endVector = clock();

	clock_t startDeque = clock();
	std::vector<int>::iterator it = _cvector.begin();
	std::vector<int>::iterator ite = _cvector.end();
	for (it = _cvector.begin(); it != ite; it++)
		_cdeque.push_back(*it);	

	mergeInsertSort(_cdeque);
	displayContainer(_cvector, 'a');
	clock_t endDeque = clock();


	std::cout << std::endl;
	double timeVector = ((double) (endVector - _startVector) / CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << _cvector.size() << " elements with std::vector :" << timeVector * 1000.0 << " ms" << std::endl;

	double timeDeque = ((double) (endDeque - startDeque) / CLOCKS_PER_SEC); 
	std::cout << "Time to process a range of " << _cdeque.size() << " elements with std::deque :" << timeDeque * 1000.0 << " ms" << std::endl;
}

/*private Function*/
template <typename T>
void PmergeMe::displayContainer(T &container, char c)
{
	if (c == 'b')
		std::cout << "Before: ";
	else if (c == 'a')
	{
		std::cout << std::endl;
		std::cout << "After:  ";
	}

	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	for (it = container.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;

}

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
	_startVector = clock();
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
}

template <typename T>
static void InsertSort(T &container)
{
	typename T::iterator i, j, key;
	for (i = container.begin() + 1; i != container.end(); i++)
	{
		key = i;
		for (j = i - 1; j >= container.begin() && *j > *key; j--)
		{
			std::swap(*j, *(j + 1));
			key--;
		}
	}
}

template <typename T>
static void mergeSort(T &container, T &ct1, T&ct2)
{
	typename T::iterator i = ct1.begin();
	typename T::iterator j = ct2.begin();

	while (i != ct1.end() && j != ct2.end())
	{
		while (j != ct2.end() && *i > *j)
		{
			container.push_back(*j);
			j++;

		}
		container.push_back(*i);
		i++;
	}
	while (j != ct2.end())
	{
		container.push_back(*j);
		j++;
	}
	while (i != ct1.end())
	{
		container.push_back(*i);
		i++;
	}
}

template <typename T>
void PmergeMe::mergeInsertSort(T &container)
{

	if (container.size() <= 15)
	{
		InsertSort(container);
		return ;
	}
	
	typename T::iterator middle = container.begin() + container.size() / 2;
	T ct1(container.begin(), middle);
	T ct2(middle, container.end());

	mergeInsertSort(ct1);
	mergeInsertSort(ct2);

	container.clear();
	mergeSort(container, ct1, ct2);
}
