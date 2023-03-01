/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:53:37 by rburgsta          #+#    #+#             */
/*   Updated: 2023/03/01 17:40:58 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed area(Point a, Point b, Point c)
{
	Fixed out;

	std::cout << "###" << a.getX() * (b.getY() - c.getY()) <<std::endl;
	out = a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - 
	a.getY()) + c.getX() * (a.getY() - b.getY()) / 2;
	if (out.getRawBits() > 0)
		out.setRawBits(-out.getRawBits());
	return (out);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) 
{
	std::cout << area(a, b, c) << " == " << area(point, b, c) << " + " << area(point, a, c) << " + " << area(point, a, b) << std::endl;
	return (area(a, b, c) == area(point, b, c) + area(point, a, c) + area(point, a, b));
}