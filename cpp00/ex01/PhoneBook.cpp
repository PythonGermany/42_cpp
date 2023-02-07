/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:48:50 by rburgsta          #+#    #+#             */
/*   Updated: 2023/02/07 02:25:49 by rburgsta         ###   ########.fr       */
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

	for (i = 0; i < 8; i++)
	{
		if (this->contacts[i].getInitialized())
		{
			for (size_t i = 0; i < 9; i++)
				std::cout << " ";
			std::cout << i << "|";
			this->contacts[i].column();
		}
	}
	while (true)
	{
		std::cout << "Enter valid index: ";
		std::cin >> i;
		std::cout << "DEBUG: index: [" << i << "]" << std::endl;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (i >= 0 && i < 8 && this->contacts[i].getInitialized())
			break;
	}
	this->contacts[i].print();
}
