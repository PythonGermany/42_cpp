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

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const& rhs)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = rhs;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs)
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::convert(std::string& literal)
{
	
}