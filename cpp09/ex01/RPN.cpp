#include "RPN.hpp"

bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

int calculate(int a, int b, char sign)
{
	int res = 0;
	switch(sign)
	{
		case '+':
		{
			res = a + b;
			break ;
		}
		case '-':
		{
			res = a - b;
			break ;
		}
		case '*':
		{
			res = a * b;
			break ;
		}
		case '/':
		{
			if (b == 0)
				throw std::logic_error("Error");
			res = a / b;
			break ;
		}
		default:
		{
			throw std::logic_error("Error");
			break ;
		}
	}
	return res;
}


/* Member Function */
void RPN::execute(std::string expression)
{
	if (expression[0] == ' ')
		throw std::logic_error("Error");

	std::stack<int> _operand;
	for (int i = 0; expression[i]; i++)
	{
		if (isdigit(expression[i]) == true || expression[i] == ' '
				|| isOperator(expression[i]) == true)
		{
			if (isdigit(expression[i]) == true
					&& (expression[i + 1] == '\0' || expression[i + 1] == ' '))
				_operand.push(atoi(&expression[i]));
			else if (isOperator(expression[i]) == true
					&& (expression[i + 1] == '\0' || expression[i + 1] == ' '))
			{
				int b = _operand.top();
				_operand.pop();
				int a = 0;
				if (_operand.empty() == false)
				{
					a = _operand.top();
					_operand.pop();
				}
				else 
				{
					throw std::logic_error("Error");
				}
				std::cout << "a et b : " << a << " " << b << " sign = " << expression[i] << std::endl; 
				int res = calculate(a, b, expression[i]);
				_operand.push(res);
			}
			else if(expression[i] == ' ' && (expression[i - 1] == ' ' || expression[i + 1] == '\0'))
			{
				throw std::logic_error("Error");
			}
		}
		else
		{
			throw std::logic_error("Error");
		}
	}
	std::cout << _operand.top() << std::endl;
}
