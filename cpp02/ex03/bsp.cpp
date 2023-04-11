/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:53:37 by rburgsta          #+#    #+#             */
/*   Updated: 2023/04/11 16:43:05 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed area(Point const& a, Point const& b, Point const& c)
{
	Fixed out;

	out = a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());
 	if (out.getRawBits() < 0)
		out.setRawBits(-out.getRawBits());
	return (out);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) 
{
	Fixed areaABC = area(a, b, c);
	Fixed areaPBC = area(point, b, c);
	Fixed areaPAC = area(point, a, c);
	Fixed areaPAB = area(point, a, b);
	if (areaPBC == 0 || areaPAC == 0 || areaPAB == 0)
		return (0);
	return (areaABC >= areaPBC + areaPAC + areaPAB);
}