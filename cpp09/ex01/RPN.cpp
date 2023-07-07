/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:55:04 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/30 16:55:04 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string expr)
{
	loadExpression(expr);
}

RPN::RPN(RPN const& rhs)
{
	*this = rhs;
}

RPN& RPN::operator=(RPN const& rhs)
{
	if (this == &rhs)
		return (*this);
	data = rhs.data;
	stack = rhs.stack;
	return (*this);
}

RPN::~RPN()
{
}

t_element createElement(int type, int value)
{
	t_element el;

	el.type = type;
	el.value = value;
	return (el);
}

void RPN::loadExpression(std::string expr)
{
	if (expr.length() < 1)
		handleError("Loading: Empty input expression", 1);
	int exprSize = expr.length();
	for (int i = exprSize - 1; i >= 0; i -= 2)
	{
		if (std::isdigit(expr[i]) && i != exprSize - 1)
			data.push_front(createElement(OPERAND,
				std::atoi(expr.substr(i, expr.find(' ')).c_str())));
		else if (std::strchr("+-/*", expr[i]) != NULL)
			data.push_front(createElement(OPERATOR, expr[i]));
		else
			handleError("Loading: Invalid input expression", 1);
		if (i > 0 && expr[i - 1] != ' ')
			handleError("Loading: Invalid input expression", 1);
	}
}

int RPN::processExpression()
{
	while (data.size() > 0)
	{
		if (data.front().type == OPERAND)
			stack.push_front(data.front());
		else if (data.front().type == OPERATOR)
		{
			if (stack.size() < 2)
				handleError("Processing: Invalid expression", 1);
			if (data.front().value == '+')
				(*(++stack.begin())).value += stack.front().value;
			else if (data.front().value  == '-')
				(*(++stack.begin())).value -= stack.front().value;
			else if (data.front().value == '*')
				(*(++stack.begin())).value *= stack.front().value;
			else if (data.front().value == '/')
				(*(++stack.begin())).value /= stack.front().value;
			stack.pop_front();
		}
		data.pop_front();
	}
	if (stack.size() != 1)
		handleError("Processing: Invalid/Incomplete expression", 1);
	return (stack.front().value);
}

void RPN::handleError(std::string msg, int exitCode)
{
	std::cout << "Error: " << msg << "!" << std::endl;
	std::exit(exitCode);
}