/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:42:29 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:41:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
  std::cout << "WrongCat default constructor called" << std::endl;
  type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const& src) : WrongAnimal(src) {
  std::cout << "WrongCat copy constructor called" << std::endl;
  *this = src;
}

WrongCat& WrongCat::operator=(WrongCat const& rhs) {
  std::cout << "WrongCat copy assignment operator called" << std::endl;
  this->type = rhs.type;
  return (*this);
}

WrongCat::~WrongCat(void) {
  std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
  std::cout << "Meaaaaoowwwwwww" << std::endl;
}