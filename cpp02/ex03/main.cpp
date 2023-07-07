/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:36:57 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:37:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
  bool isintri = bsp(Point(-4, 0), Point(4, 0), Point(0, 4), Point(0, 2.12525));
  std::cout << "Is inside triangle: " << isintri << std::endl;

  isintri = bsp(Point(4, 0), Point(0, 4), Point(0, 0), Point(0, 2.12525));
  std::cout << "Is inside triangle: " << isintri << std::endl;

  isintri = bsp(Point(4, 0), Point(0, -4), Point(0, 0), Point(0, 2.12525));
  std::cout << "Is inside triangle: " << isintri << std::endl;

  isintri = bsp(Point(4, 0), Point(0, -4), Point(0, 0), Point(3, -0.05));
  std::cout << "Is inside triangle: " << isintri << std::endl;
  return 0;
}