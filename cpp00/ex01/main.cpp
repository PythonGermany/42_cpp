/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:19:00 by rburgsta          #+#    #+#             */
/*   Updated: 2023/01/03 09:00:45 by rburgsta         ###   ########.fr       */
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
		//else if (input == "SEARCH")
	}
}
