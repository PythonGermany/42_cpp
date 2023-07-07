/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:36:22 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 23:36:22 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const& rhs)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = rhs;
}

Intern& Intern::operator=(Intern const& rhs)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string const& name, std::string const& target) const
{
	AForm *form = NULL;
	if (name == "ShrubberyCreationForm")
		form = new ShrubberyCreationForm(target);
	else if (name == "RobotomyRequestForm")
		form = new RobotomyRequestForm(target);
	else if (name == "PresidentialPardonForm")
		form = new PresidentialPardonForm(target);
	if (form == NULL)
		std::cout << "Intern: Form with the name " << name << " does not exist" << std::endl;
	else
		std::cout << "Intern creates " << name << std::endl;
	return (form);
}