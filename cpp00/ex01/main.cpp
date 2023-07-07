/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:19:00 by rburgsta          #+#    #+#             */
/*   Updated: 2023/02/06 17:39:36 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	std::string input;
	PhoneBook pb;
	
	input = "GO";
	while (input != "EXIT")
	{
		std::cout << "Type 'ADD', 'SEARCH' or 'EXIT': ";
		std::cin >> input;
		if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "EXIT")
			return (0);
	}
}
