/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:42:58 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:40:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
  std::cout << "Dog default constructor called" << std::endl;
  type = "Dog";
  b = new Brain();
}

Dog::Dog(Dog const& src) : Animal(src) {
  std::cout << "Dog copy constructor called" << std::endl;
  *this = src;
}

Dog& Dog::operator=(Dog const& rhs) {
  std::cout << "Dog copy assignment operator called" << std::endl;
  this->type = rhs.type;
  this->b = new Brain(*rhs.b);
  return (*this);
}

Dog::~Dog(void) {
  std::cout << "Dog destructor called" << std::endl;
  delete b;
}

void Dog::makeSound(void) const { std::cout << "Dog sound" << std::endl; }

Brain* Dog::getBrain() const { return (b); }