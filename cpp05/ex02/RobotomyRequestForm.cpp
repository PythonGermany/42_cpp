/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:29:43 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 21:29:43 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45) {
  std::cout << "RobotomyRequestForm default constructor called" << std::endl;
  this->target = "noname";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    : AForm("RobotomyRequestForm", 72, 45) {
  std::cout << "RobotomyRequestForm constructor called" << std::endl;
  this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& rhs)
    : AForm("RobotomyRequestForm", 72, 45) {
  std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
  *this = rhs;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    RobotomyRequestForm const& rhs) {
  std::cout << "RobotomyRequestForm copy assignment operator called"
            << std::endl;
  this->target = rhs.target;
  return (*this);
}

void RobotomyRequestForm::executeFormTask() const {
  static bool first = true;
  std::cout << "* drilling noises *, ";
  if (first == true) {
    srand(time(NULL));
    first = false;
  }
  if (rand() % 2 == 0)
    std::cout << target << " has been robotomized" << std::endl;
  else
    std::cout << "The robotomy of " << target << " was unsuccessful"
              << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called" << std::endl;
}
