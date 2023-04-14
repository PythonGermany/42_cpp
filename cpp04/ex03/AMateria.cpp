/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:39:54 by rburgsta          #+#    #+#             */
/*   Updated: 2023/04/15 01:08:34 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : type(type)
{
	std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(AMateria const& src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria& AMateria::operator=(AMateria const& rhs)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const& AMateria::getType() const
{
	return (type);
}
