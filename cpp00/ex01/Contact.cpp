/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:42:09 by rburgsta          #+#    #+#             */
/*   Updated: 2023/01/03 08:59:15 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::init()
{
	std::string input;

	input = "\n";
	while (input == "\n")
	{
		std::cout << "Enter first name: ";
		std::cin >>input;
	}
	this->first_name = input;
}
