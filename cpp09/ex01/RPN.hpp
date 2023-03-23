#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <exception>

class RPN
{
	public:
		
		static void execute(std::string expression);

	private:

		RPN(void);
		~RPN(void);
		RPN(const RPN& toCopy);
		RPN& operator=(const RPN& toCopy);

};

#endif
