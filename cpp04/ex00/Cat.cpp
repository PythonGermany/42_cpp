/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:42:29 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:39:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
  std::cout << "Cat default constructor called" << std::endl;
  type = "Cat";
}

Cat::Cat(Cat const& src) : Animal(src) {
  std::cout << "Cat copy constructor called" << std::endl;
  *this = src;
}

Cat& Cat::operator=(Cat const& rhs) {
  std::cout << "Cat copy assignment operator called" << std::endl;
  this->type = rhs.type;
  return (*this);
}

Cat::~Cat(void) { std::cout << "Cat destructor called" << std::endl; }

void Cat::makeSound(void) const { std::cout << "Cat sound" << std::endl; }