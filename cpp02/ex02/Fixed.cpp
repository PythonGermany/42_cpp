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
#include <cmath>

const int Fixed::fractionalBits = 8;

Fixed::Fixed(void) : number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb) : number(nb << 8)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->number = nb * (1 << this->fractionalBits) + (nb >= 0 ? 0.5 : -0.5);
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->number = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator>(Fixed const& rhs)
{
	return (this->number > rhs.number);
}

bool Fixed::operator<(Fixed const& rhs)
{
	return (this->number < rhs.number);
}

bool Fixed::operator>=(Fixed const& rhs)
{
	return (this->number >= rhs.number);
}

bool Fixed::operator<=(Fixed const& rhs)
{
	return (this->number <= rhs.number);
}

bool Fixed::operator==(Fixed const& rhs)
{
	return (this->number == rhs.number);
}

bool Fixed::operator!=(Fixed const& rhs)
{
	return (this->number != rhs.number);
}

Fixed Fixed::operator+(Fixed const& rhs)
{
	Fixed ret;

	ret.setRawBits(this->number + rhs.number);
	return (ret);
}

Fixed Fixed::operator-(Fixed const& rhs)
{
	Fixed ret;

	ret.setRawBits(this->number - rhs.number);
	return (ret);
}

Fixed& Fixed::min(Fixed& nb1, Fixed& nb2)
{
	if (nb1 <= nb2)
		return (nb1);
	return (nb2);
}

Fixed& Fixed::max(Fixed& nb1, Fixed& nb2)
{
	if (nb1 >= nb2)
		return (nb1);
	return (nb2);
}

Fixed& Fixed::min(Fixed const& nb1, Fixed const& nb2)
{
	if ((Fixed)nb1 <= nb2)
		return ((Fixed&)nb1);
	return ((Fixed&)nb2);
}

Fixed& Fixed::max(Fixed const& nb1, Fixed const& nb2)
{
	if ((Fixed)nb1 >= nb2)
		return ((Fixed&)nb1);
	return ((Fixed&)nb2);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	this->number = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

float Fixed::toFloat(void) const
{
	return ((float)this->number / (1 << this->fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->number >> 8);
}

std::ostream& operator<<(std::ostream& os, Fixed const& rhs)
{
	os << rhs.toFloat();
	return (os);
}