/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:36:57 by rburgsta          #+#    #+#             */
/*   Updated: 2023/03/01 19:58:53 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	bool isintri = bsp(Point(-4, 0), Point(4, 0), Point(0, 4), Point(0, 2.12525));
	std::cout << "Is inside triangle: " << isintri << std::endl;
	return 0;
}