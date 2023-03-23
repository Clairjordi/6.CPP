#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please, put a one argument" << std::endl;
		return 1;
	}
	try 
	{
		RPN::execute(argv[1]);
	}
	catch (std::exception & e)
	{
		std::cout << "Error" << std::endl;
	}
}
