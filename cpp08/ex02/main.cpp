/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:10:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/14 16:37:22 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <list>

int main()
{
	std::cout << "~~~Test with std::stack<int> : ~~~" << std::endl;
	{
		MutantStack<int> mstack;

		std::cout << "size of stack  = " << mstack.size() << std::endl;

		mstack.push(5);
		mstack.push(17);

		std::cout << "last element {5, 17} = " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "size of stack [after pop] = " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "stack {5, 3, 5, 737, 0} : " << std::endl;
		try{
			if (it < mstack.begin() || it > mstack.end())
				throw std::out_of_range("Invalid it");
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}
		catch(std::exception & e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}

		std::stack<int> s(mstack);
		std::cout << "last element (s - by copy) {5, 3, 5, 737, 0} = " << mstack.top() << std::endl;

	}
	std::cout << std::endl;
	std::cout << "~~~Test with std::list : ~~~" << std::endl;
	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << "last element {5, 17} = " << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << "size of stack [after pop] = " << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "stack {5, 3, 5, 737, 0} : " << std::endl;
		try{
			if (std::distance(mstack.begin(), it) < 0 || std::distance(it, mstack.end()) <= 0)
				throw std::out_of_range("Invalid it");
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}
		catch(std::exception & e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "~~~Test with std::stack<char> : ~~~" << std::endl;
	{
		MutantStack<char> mstack;

		mstack.push('c');
		mstack.push('h');
		mstack.push('e');

		std::cout << "last element {c, h, e} = " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "size of stack [after pop] = " << mstack.size() << std::endl;
		std::cout << "last element {c, h} = " << mstack.top() << std::endl;

		mstack.push('a');
		mstack.push('r');
		
		MutantStack<char>::iterator it = mstack.begin();
		std::cout << "begin() {c, h, a, r} = " << *it << std::endl;
		MutantStack<char>::iterator ite = mstack.end();

		++it;
		std::cout << "stack {c, h, a, r} after ++it : " << std::endl;
		try{
			if (it < mstack.begin() || it > mstack.end())
				throw std::out_of_range("Invalid it");
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}
		catch(std::exception & e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}

		--it;
		std::cout << "stack {c, h, a, r} after --it :  " << std::endl;
		try{
			if (it < mstack.begin() || it > mstack.end())
				throw std::out_of_range("Invalid it");
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}
		catch(std::exception & e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}
		++it;
		++it;
		std::cout << "stack {c, h, a, r} after ++it x2:  " << std::endl;
		try{
			if (it < mstack.begin() || it > mstack.end())
				throw std::out_of_range("Invalid it");
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}
		catch(std::exception & e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}

	}
	std::cout << std::endl;
	std::cout << "~~~Test with std::stack<float> : ~~~" << std::endl;
	{
		MutantStack<float> mstack;

		mstack.push(3.4f);
		mstack.push(7.8f);
		mstack.push(6.3f);

		std::cout << "last element {3.4f, 7.8f, 6.3f} = " << mstack.top() << std::endl;

		std::cout << "size of stack = " << mstack.size() << std::endl;


		MutantStack<float>::iterator it = mstack.begin();
		MutantStack<float>::iterator ite = mstack.end();

		std::cout << "stack {3.4f, 7.8f, 6.3f} : " << std::endl;
		try{
			if (it < mstack.begin() || it > mstack.end())
				throw std::out_of_range("Invalid it");
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}
		catch(std::exception & e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}
		--ite;
		--ite;
		std::cout << "stack {3.4f, 7.8f, 6.3f} after --itex2 : " << std::endl;
		try{
			if (ite < mstack.begin() || ite > mstack.end())
				throw std::out_of_range("Invalid it");
			while (it != ite)
			{
				std::cout << *ite << std::endl;
				++ite;
			}
		}
		catch(std::exception & e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}
		++ite;
		std::cout << "stack {3.4f, 7.8f, 6.3f} after ++ite : " << std::endl;
		try{
			if (ite < mstack.begin() || ite > mstack.end())
				throw std::out_of_range("Invalid it");
			while (it != ite)
			{
				std::cout << *ite << std::endl;
				++ite;
			}
		}
		catch(std::exception & e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}

	}

	return 0;
}
