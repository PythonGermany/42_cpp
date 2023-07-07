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
	int i = 0;
	const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (; i < 3; i++)
		if (name == names[i])
			break ;
	if (i < 3)
		std::cout << "Intern creates " << name;
	switch (i)
	{
	case 0:
		return (new ShrubberyCreationForm(target));	
	case 1:
		return (new RobotomyRequestForm(target));
	case 2:
		return (new PresidentialPardonForm(target));
	default:
		std::cout << "Intern: Form type " << name << " does not exist";
	}
	return (NULL);
}