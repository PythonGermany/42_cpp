/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:40:13 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:40:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("UndefinedAnimal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const& src) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = src;
}

Animal& Animal::operator=(Animal const& rhs) {
  std::cout << "Animal copy assignment operator called" << std::endl;
  this->type = rhs.type;
  return (*this);
}

Animal::~Animal(void) { std::cout << "Animal destructor called" << std::endl; }

void Animal::makeSound(void) const {
  std::cout << "UndefinedAnimalSound" << std::endl;
}

std::string Animal::getType(void) const { return (type); }