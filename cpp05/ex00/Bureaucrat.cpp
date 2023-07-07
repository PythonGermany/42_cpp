/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:01:25 by rburgsta          #+#    #+#             */
/*   Updated: 2023/04/22 16:58:51 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int const grade) : name(name)
{
	std::cout << "########## constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = rhs.name;
	this->grade = rhs.grade;
	return (*this);
}

std::string& Bureaucrat::getName() const
{
	return ()
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (os);
}