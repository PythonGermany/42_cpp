/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:14:39 by rburgsta          #+#    #+#             */
/*   Updated: 2023/04/14 14:54:15 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct("Bob");
	ClapTrap ct2("Peter");

	ct.takeDamage(4);
	ct.takeDamage(5);
	ct.beRepaired(14);
	ct.attack("Tom");
	for (size_t i = 0; i < 9; i++)
		ct.attack("John");
	ct.beRepaired(15);
	ct.takeDamage(18);
	ct.beRepaired(15);
	ct.attack("John");

	ct2.takeDamage(299);
	return (0);
}