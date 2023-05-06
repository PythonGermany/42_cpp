/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:18:14 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 20:18:14 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("noname"), isSigned(false), signReq(1), exeReq(1)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int sR, int const eR) : name(name), signReq(sR), exeReq(eR)
{
	std::cout << "AForm constructor called" << std::endl;
	if (sR < HIGHEST_GRADE || eR < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (sR > LOWEST_GRADE || eR > LOWEST_GRADE)
		throw GradeTooLowException();
	isSigned = false;
}

AForm::AForm(AForm const& rhs) : name(rhs.name), signReq(rhs.signReq), exeReq(rhs.exeReq)
{
	std::cout << "AForm copy constructor called" << std::endl;
	isSigned = rhs.isSigned;
}

AForm& AForm::operator=(AForm const& rhs)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	const_cast<std::string&>(name) = rhs.getName();
	const_cast<int&>(signReq) = rhs.getSignReq();
	const_cast<int&>(exeReq) = rhs.getExeReq();
	isSigned = rhs.getSigned();
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string const& AForm::getName() const
{
	return (name);
}

bool const& AForm::getSigned() const
{
	return (isSigned);
}

int const& AForm::getSignReq() const
{
	return (signReq);
}

int const& AForm::getExeReq() const
{
	return (exeReq);
}

void AForm::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() <= signReq)
		isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (isSigned == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > exeReq)
		throw GradeTooLowException();
	executeFormTask();
}

const char* AForm::GradeTooHighException::what() const throw() 
{
	return ("AForm: Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw() 
{
	return ("AForm: Grade too low!");
}

const char* AForm::FormNotSignedException::what() const throw() 
{
	return ("AForm: Form not signed!");
}

std::ostream& operator<<(std::ostream& os, AForm const& rhs)
{
	os << rhs.getName() << ", Aform sign requirement: " << rhs.getSignReq();
	os << ", exectuion requirement: " << rhs.getExeReq();
	os << ", is signed: " << rhs.getSigned() << ".";
	return (os);
}
