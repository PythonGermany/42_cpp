/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:02:14 by rburgsta          #+#    #+#             */
/*   Updated: 2023/02/17 16:02:14 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(void) : number(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed& Fixed::operator=(Fixed const& rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->number = rhs.getRawBits();
  return (*this);
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

void Fixed::setRawBits(int const raw) { this->number = raw; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->number);
}