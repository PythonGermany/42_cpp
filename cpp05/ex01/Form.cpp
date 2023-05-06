/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:18:14 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 20:18:14 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("noname"), isSigned(false), signReq(1), exeReq(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int sR, int const eR) : name(name), signReq(sR), exeReq(eR)
{
	std::cout << "Form constructor called" << std::endl;
	if (sR < HIGHEST_GRADE || eR < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (sR > LOWEST_GRADE || eR > LOWEST_GRADE)
		throw GradeTooLowException();
	isSigned = false;
}

Form::Form(Form const& rhs) : name(rhs.name), signReq(rhs.signReq), exeReq(rhs.exeReq)
{
	std::cout << "Form copy constructor called" << std::endl;
	isSigned = rhs.isSigned;
}

Form& Form::operator=(Form const& rhs)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	const_cast<std::string&>(name) = rhs.getName();
	const_cast<int&>(signReq) = rhs.getSignReq();
	const_cast<int&>(exeReq) = rhs.getExeReq();
	isSigned = rhs.getSigned();
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string const& Form::getName() const
{
	return (name);
}

bool const& Form::getSigned() const
{
	return (isSigned);
}

int const& Form::getSignReq() const
{
	return (signReq);
}

int const& Form::getExeReq() const
{
	return (exeReq);
}

void Form::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() <= signReq)
		isSigned = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() 
{
	return ("Form: Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw() 
{
	return ("Form: Grade too low!");
}

std::ostream& operator<<(std::ostream& os, Form const& rhs)
{
	os << rhs.getName() << ", form sign requirement: " << rhs.getSignReq();
	os << ", exectuion requirement: " << rhs.getExeReq();
	os << ", is signed: " << rhs.getSigned() << ".";
	return (os);
}
