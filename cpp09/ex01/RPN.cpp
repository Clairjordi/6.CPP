#include "RPN.hpp"

static bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

static int calculate(int a, int b, char sign)
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

static bool checkOnlyDigit(std::string str)
{
	int ope = 0;
	int digit = 0;
	for (int i = 0; str[i]; i++)
	{
		if (isOperator(str[i]) == true)
			ope++;
		if (isdigit(str[i]) == true)
			digit++;
	}
	if (ope == 0 || ope != digit - 1)
		throw std::logic_error("Error");
	return true;
}


/* Member Function */
void RPN::execute(std::string expression)
{
	if (expression[0] == ' ' || isOperator(expression[0]) == true || expression == "")
		throw std::logic_error("Error");

	if (checkOnlyDigit(expression) == false)
		throw std::logic_error("Error");
	std::stack<int> _operand;
	for (int i = 0; expression[i]; i++)
	{
		if ((isdigit(expression[i]) == true && expression[i + 1] == ' ')
				|| (isOperator(expression[i]) == true && (expression[i + 1] == '\0' || expression[i + 1] == ' '))
				|| expression[i] == ' ')
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
					throw std::logic_error("Error");
				int res = calculate(a, b, expression[i]);
				_operand.push(res);
			}
			else if(expression[i] == ' ' && (expression[i - 1] == ' ' || expression[i + 1] == '\0'))
			{
				throw std::logic_error("Error");
			}
		}
		else
			throw std::logic_error("Error");
	}
	std::cout << _operand.top() << std::endl;
}
