#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	public:
		
		static void execute(std::string expression);

	private:
		std::stack<int> _operand;

		RPN(void);
		~RPN(void);
		RPN(const RPN& toCopy);
		RPN& operator=(const RPN& toCopy);

};

#endif
