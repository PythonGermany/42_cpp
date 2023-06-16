/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:42:58 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:39:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
  std::cout << "Dog default constructor called" << std::endl;
  type = "Dog";
}

Dog::Dog(Dog const& src) : Animal(src) {
  std::cout << "Dog copy constructor called" << std::endl;
  *this = src;
}

Dog& Dog::operator=(Dog const& rhs) {
  std::cout << "Dog copy assignment operator called" << std::endl;
  this->type = rhs.type;
  return (*this);
}

Dog::~Dog(void) { std::cout << "Dog destructor called" << std::endl; }

void Dog::makeSound(void) const { std::cout << "Dog sound" << std::endl; }