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
	// if (_cvector.size() < 11)
		// _threshold = 3;
	// else
		// _threshold = 10;
	displayContainer(_cvector, 'b');
	mergeInsertSort(_cvector);
	mergeInsertSort(_cdeque);
	displayContainer(_cvector, 'a');
}

/*private Function*/
template <typename T>
void PmergeMe::displayContainer(T &container, char c)
{
	if (c == 'b')
		std::cout << "Before: ";
	else if (c == 'a')
		std::cout << "After:  ";

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

	std::vector<int>::iterator it = _cvector.begin();
	std::vector<int>::iterator ite = _cvector.end();
	for (it = _cvector.begin(); it != ite; it++)
		_cdeque.push_back(*it);	
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
	//comparer le premier element de ct1 avec le premier element de ct2 
	//si ct2 < ct1 
	//alors on container.push_back(ct2.at(ct2.begin()))
	//a la fin de la boucle on ajoute le premier element de ct1 car c'est lui qui sera le plus petit
	typename T::iterator i;
	for (i = ct1.begin(); i != ct1.end() ;i++)
	{
		while (j != ct2.end()) // faire un while pour garder la pos iterator j et break quand il est arrive a la fin 
		for (typename T::iterator j = ct2.begin(); j != ct2.end() && ct2.empty() == false ;j++)
		{
			if (*i > *j)
			{
				container.push_back(*j);
			}
		}
		container.push_back(*i);

	}
	//finir de push le ct1 dans container 
	
}

template <typename T>
void PmergeMe::mergeInsertSort(T &container)
{

	if (container.size() <= 3) //seuil a mettre ?
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
