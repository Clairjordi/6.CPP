/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:10:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/11 13:22:13 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

class Test{
	public:
		Test() {
			_str = "ok";
		}
		std::string getStr() const {
			return _str;
		}
		virtual ~Test(){};
	private:
		std::string _str;
};

std::ostream & operator<<(std::ostream & o, const Test & i){
	o << i.getStr();
	return o;
}

int main()
{

	 std::cout << "Test with array of char :" << std::endl;
	{
		try
		{
			Array<char> array(2);

			std::cout << "size of array = " << array.size() << std::endl;
			for (int i = 0; i < 2; i++)
				std::cout << "array[" << i << "] = '" << array[i] << "'" << std::endl;
			array[1] = 'a';
			std::cout << "[after assignement] array[1] = '" << array[1] << "'" << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cout << "ERREUR: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Test with array of string :" << std::endl;
	{
		try
		{
			Array<std::string> array(2);

			std::cout << "size of array = " << array.size() << std::endl;
			for (int i = 0; i < 2; i++)
				std::cout << "array[" << i << "] = \"" << array[i] << "\"" << std::endl;
			array[0] = "It's";
			array[1] = "modified";
			std::cout << "[after assignement] : " << std::endl;
			for (int i = 0; i < 2; i++)
				std::cout << "array[" << i << "] = " << array[i] << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cout << "ERREUR: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Test with array of double :" << std::endl;
	{
		try
		{
			Array<double> array(4);

			std::cout << "size of array = " << array.size() << std::endl;
			for (int i = 0; i < 4; i++)
				std::cout << "array[" << i << "] = " << array[i] << std::endl;
			for (int i = 0; i < 4; i++)
				array[i] = 85.25;
			std::cout << "[after assignement] : " << std::endl;
			for (int i = 0; i < 4; i++)
				std::cout << "array[" << i << "] = " << array[i] << std::endl;
			std::cout << "array[4] = " << array[4] << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cout << "ERREUR: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Test with default constructor (array == NULL) :" << std::endl;
	{
		try
		{
			Array<float> array;
			std::cout << "size of array = " << array.size() << std::endl;
			std::cout << "array[0] = " << array[0] << std::endl;

		}
		catch (std::exception const & e)
		{
			std::cout << "ERREUR: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Test with array of class :" << std::endl;
	{
		try
		{
			Array<Test> array(3);

			std::cout << "size of array = " << array.size() << std::endl;
			for (int i = 0; i < 3; i++)
				std::cout << "array[" << i << "] = " << array[i] << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cout << "ERREUR: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Test with array of int by copy :" << std::endl;
	{
		try
		{
			Array<int> array2(5);
			Array<int> array(array2);


			std::cout << "size of array = " << array.size() << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "array[" << i << "] = " << array[i] << std::endl;
			for (int i = 0; i < 5; i++)
				array[i] = i + 1;
	
			std::cout << "[after assignement] : " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "array[" << i << "] = " << array[i] << std::endl;

		}
		catch (std::exception const & e)
		{
			std::cout << "ERREUR: " << e.what() << std::endl;
		}
	}
	return 0;
}
