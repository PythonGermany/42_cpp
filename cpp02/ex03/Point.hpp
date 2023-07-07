/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:34:50 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:37:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
 private:
  Fixed const x;
  Fixed const y;

 public:
  Point();
  Point(const float x, const float y);
  Point(Point const& src);
  Point& operator=(Point const& rhs);
  ~Point();

  Fixed getX(void) const;
  Fixed getY(void) const;
};

#endif