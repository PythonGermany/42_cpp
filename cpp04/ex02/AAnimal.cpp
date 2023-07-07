/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:40:13 by rburgsta          #+#    #+#             */
/*   Updated: 2023/03/08 20:02:21 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("UndefinedAAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const& src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal& AAnimal::operator=(AAnimal const& rhs)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (type);
}