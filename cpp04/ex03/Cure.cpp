/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:47:56 by rburgsta          #+#    #+#             */
/*   Updated: 2023/03/10 18:16:20 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const& src)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure& Cure::operator=(Cure const& rhs)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}