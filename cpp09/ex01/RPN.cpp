#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

int RPN::calculate(std::string rpns)
{
	std::istringstream iss(rpns);
	std::string tok;
	std::stack<double> stack;
	double result = 0;

	while (iss >> tok)
	{
		if (isdigit(tok[0]))
		{
			double value = std::stod(tok);
			stack.push(value);
		}
		else if (tok == "+" || tok == "-" || tok == "/" || tok == "*")
		{
			if (stack.size() < 2)
				throw (std::runtime_error("ERROR: missing operands"));
			
			double n1 = stack.top();
			stack.pop();
			double n2 = stack.top();
			stack.pop();

			if (tok == "+")
				stack.push(n2 + n1);
			else if (tok == "-")
				stack.push(n2 - n1);
			else if (tok == "*")
				stack.push(n2 * n1);
			else if (tok == "/")
			{
				if (n1 == 0)
					throw (std::runtime_error("ERROR: zero division error"));
				stack.push(n2 / n1);
			}
		}
		else
			throw (std::runtime_error("ERROR: invalid expression"));
	}
	if (stack.size() != 1)
		throw (std::runtime_error("ERROR: too many expressions"));
	result = stack.top();
	stack.pop();
	return (result);
}

RPN::RPN()
{

}

RPN::RPN(const RPN& rhs)
{
	(void )rhs;
}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
	{
		/* THEY ARE NOT THE SAME */
	}
	return (*this);
}

RPN::~RPN()
{

}