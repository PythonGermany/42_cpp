/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:33:56 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:41:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("UndefinedWrongAnimal") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& src) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = src;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs) {
  std::cout << "WrongAnimal copy assignment operator called" << std::endl;
  this->type = rhs.type;
  return (*this);
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "UndefinedWrongAnimalSound" << std::endl;
}

std::string WrongAnimal::getType(void) const { return (type); }