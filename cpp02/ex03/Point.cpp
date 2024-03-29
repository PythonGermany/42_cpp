/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:34:24 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:37:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
  std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y) {
  std::cout << "Point assignment constructor called" << std::endl;
}

Point::Point(Point const& src) {
  std::cout << "Point copy constructor called" << std::endl;
  *this = src;
}

Point& Point::operator=(Point const& rhs) {
  std::cout << "Point copy assignment operator called" << std::endl;
  (Fixed) this->x = rhs.x;
  (Fixed) this->y = rhs.y;
  return (*this);
}

Point::~Point(void) { std::cout << "Point destructor called" << std::endl; }

Fixed Point::getX(void) const { return (this->x); }

Fixed Point::getY(void) const { return (this->y); }