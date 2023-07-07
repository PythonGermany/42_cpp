/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:01:25 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:42:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("noname"), grade(150) {
  std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int const grade) : name(name) {
  std::cout << "Bureaucrat constructor called" << std::endl;
  if (grade < HIGHEST_GRADE)
    throw GradeTooHighException();
  else if (grade > LOWEST_GRADE)
    throw GradeTooLowException();
  this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& rhs) {
  std::cout << "Bureaucrat copy constructor called" << std::endl;
  *this = rhs;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
  std::cout << "Bureaucrat copy assignment operator called" << std::endl;
  const_cast<std::string&>(name) = rhs.getName();
  this->grade = rhs.grade;
  return (*this);
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string const& Bureaucrat::getName() const { return (name); }

int Bureaucrat::getGrade() const { return (grade); }

void Bureaucrat::incrementGrade() {
  if (grade - 1 < HIGHEST_GRADE) throw GradeTooHighException();
  grade--;
}

void Bureaucrat::decrementGrade() {
  if (grade + 1 > LOWEST_GRADE) throw GradeTooLowException();
  grade++;
}

void Bureaucrat::signForm(Form& f) const {
  try {
    f.beSigned(*this);
    std::cout << name << " signed " << f.getName() << std::endl;
  } catch (const std::exception& e) {
    std::cout << name << " couldn't sign " << f.getName() << " because \"";
    std::cout << e.what() << "\"." << std::endl;
  }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Bureaucrat: Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Bureaucrat: Grade too low!");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs) {
  os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
  return (os);
}