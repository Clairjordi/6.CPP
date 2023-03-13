/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:10:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/13 19:55:48 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <list>

int main()
{
	std::cout << "~~~Test with std::stack<int> : ~~~" << std::endl;
	{
		MutantStack<int> mstack;

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
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
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
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;
	std::cout << "~~~Test with std::stack<char>  : ~~~" << std::endl;
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
		std::cout << *it << std::endl;
		MutantStack<char>::iterator ite = mstack.end();

		++it;

		std::cout << "stack {c, h, a, r} after ++it : " << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		--it;
		std::cout << "stack {c, h, a, r} after --it :  " << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		--it;
		--it;
		--it;
		--it;
		std::cout << "stack {c, h, a, r} after --it x4:  " << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

	}
	return 0;
}
