/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:45:31 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/30 17:45:31 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	handleError("Default constructor called", 1);
}

BitcoinExchange::BitcoinExchange(std::string inputLoc) : inputPath(inputLoc)
{
	database.open(DATABASE_LOC);
	if (database.is_open() == false)
		handleError("Could not open database", 1);
	input.open(inputLoc.c_str());
	if (input.is_open() == false)
		handleError("Could not open input file", 1);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& rhs)
{
	*this = rhs;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
	if (database.is_open() == true)
		database.close();
	database.open(DATABASE_LOC);
	if (input.is_open() == true)
		input.close();
	input.open(rhs.inputPath.c_str());
	inputPath = rhs.inputPath;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::handleError(std::string msg, int code)
{
	std::cout << "Error: " << msg << "!" << std::endl;
	std::exit(code);
}