/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:29:43 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 21:29:43 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	this->target = "noname";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& rhs) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = rhs;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	this->target = rhs.target;
	return (*this);
}

void ShrubberyCreationForm::executeFormTask() const
{
	std::ofstream outfile((target + "_shrubbery").c_str());
	
	outfile << "      *\n     ***\n    *****\n   *******\n  *********\n ***********\n     |||\n\n";
	outfile << "      *\n     ***\n    *****\n   *******\n  *********\n ***********\n     |||\n";
	outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
