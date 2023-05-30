/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:53:03 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/30 16:53:03 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

void handleError(std::string msg, int code)
{
	std::cerr << "Error: " << msg << "!" << std::endl;
	std::exit(code);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		handleError("Invalid argument count", 1);
	std::ifstream input(argv[1]);
	
	if (input.is_open() == false)
		handleError("Could not open input file", 1);
}