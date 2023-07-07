/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:36:22 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 23:36:22 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const& rhs)
{
	*this = rhs;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs)
{
	if (this == &rhs)
		return (*this);	
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string literal)
{
	if (literal.empty())
		return;
	
}

int ScalarConverter::verifyValue(std::string &value)
{
	bool precisionFound = false;
	if (value.empty())
		return (1);
	if (!value.compare("-inf") || !value.compare("+inf") || !value.compare("nan"))
		return (0);
	for (size_t i = 0; i < value.length(); i++)
	{
		if (i == 0 && (value[i] == '-' || value[i] == '+'))
			continue;
		else if (!precisionFound && value[i] == '.')
			precisionFound = true;
		else if (!std::isdigit(value[i]))
			return (1);
	}
	return (0);
}