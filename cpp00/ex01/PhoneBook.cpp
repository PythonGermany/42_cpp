/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:48:50 by rburgsta          #+#    #+#             */
/*   Updated: 2023/02/07 03:14:44 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : index(0)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void PhoneBook::add(void)
{
	if (this->index >= 8)
		this->index = 0;
	this->contacts[this->index++].init();
}

void PhoneBook::search()
{
	int i;
	int saved = 0;

	for (i = 0; i < 8; i++)
	{
		if (this->contacts[i].getInitialized())
		{
			for (size_t i = 0; i < 9; i++)
				std::cout << " ";
			std::cout << i << "|";
			this->contacts[i].column();
			saved++;
		}
	}
	if (saved == 0)
		std::cout << "ERROR: No contacts found!" << std::endl;
	while (saved != 0)
	{
		std::cout << "Enter valid index: ";
		std::cin >> i;
		if (std::cin.fail() || i < 0 || i > 7 || !this->contacts[i].getInitialized())
		{
			std::cin.clear();
			std::cout << "ERROR: Not a valid index!" << std::endl;
		}
		else
			saved = 0;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	this->contacts[i].print();
}
