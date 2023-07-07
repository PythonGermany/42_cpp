/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:29:43 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 21:29:43 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5) {
  std::cout << "PresidentialPardonForm default constructor called" << std::endl;
  this->target = "noname";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : AForm("PresidentialPardonForm", 25, 5) {
  std::cout << "PresidentialPardonForm constructor called" << std::endl;
  this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const& rhs)
    : AForm("PresidentialPardonForm", 25, 5) {
  std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
  *this = rhs;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    PresidentialPardonForm const& rhs) {
  std::cout << "PresidentialPardonForm copy assignment operator called"
            << std::endl;
  this->target = rhs.target;
  return (*this);
}

void PresidentialPardonForm::executeFormTask() const {
  std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called" << std::endl;
}
