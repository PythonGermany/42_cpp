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
	std::string line;

	database.open(DATABASE_LOC);
	if (database.is_open() == false)
		handleError("Could not open database", 1);
	std::getline(database, line);
	if (line != std::string("date,exchange_rate"))
		handleError("Wrong or missing header in database", 1);
	input.open(inputLoc.c_str());
	if (input.is_open() == false)
		handleError("Could not open input file", 1);
	std::getline(input, line);
	if (line != std::string("date | value"))
		handleError("Wrong or missing header in input", 1);
	while (std::getline(database, line))
	{
		std::string key = line.substr(0, line.find(','));
		if (verifyDate(key))
			handleError("Invalid date", 1);
		line.erase(0, line.find(',') + 1);
		if (verifyValue(line))
			handleError("Invalid value", 1);
		if (data.count(key))
			handleError("Duplicate database date", 1);
		data[key] = std::atof(line.c_str());
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs)
{
	*this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (database.is_open() == true)
		database.close();
	database.open(DATABASE_LOC);
	if (input.is_open() == true)
		input.close();
	input.open(rhs.inputPath.c_str());
	inputPath = rhs.inputPath;
	data = rhs.data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::processInput()
{
	for (std::string line; std::getline(input, line);)
	{
		std::string dateStr = line.substr(0, line.find(" | "));
		std::string valueStr = line.substr(line.find(" | ") + 3, line.length());
		if (line.find(" | ") == std::string::npos || verifyDate(dateStr) || verifyValue(valueStr))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		float value = std::atof(valueStr.c_str());
		if (value < 0)
			handleError("not a positive number.");
		else if (value > 1000)
			handleError("too large a number.");
		else
			std::cout << dateStr << " => " << value << " = "
					  << calculateValue(dateStr, value) << std::endl;
	}
}

float BitcoinExchange::calculateValue(std::string &date, float amount)
{
	float value;

	if (data.count(date))
		value = data[date];
	else
		value = (--data.upper_bound(date))->second;
	return (value * amount);
}

void BitcoinExchange::handleError(std::string msg, int exitCode)
{
	std::cout << "Error: " << msg << "!" << std::endl;
	std::exit(exitCode);
}

void BitcoinExchange::handleError(std::string msg)
{
	std::cout << "Error: " << msg << std::endl;
}

int BitcoinExchange::verifyDate(std::string &date)
{
	if (date.length() != std::string("yyyy-mm-dd").length())
		return (1);
	for (size_t i = 0; i < date.length(); i++)
		if (!std::isdigit(date[i]) && !((i == 4 || i == 7) && date[i] == '-'))
			return (1);
	int month = std::atoi(date.c_str() + 5);
	int day = std::atoi(date.c_str() + 8);
	if (month <= 0 || month > 12 || day <= 0 || day > 31)
		return (1);
	return (0);
}

int BitcoinExchange::verifyValue(std::string &value)
{
	bool precisionFound = false;
	if (value.empty())
		return (1);
	for (size_t i = 0; i < value.length(); i++)
	{
		if (i == 0 && (value[i] == '-' || value[i] == '+'))
			continue;
		else if (!precisionFound && value[i] == '.')
			precisionFound = true;
		else if (!std::isdigit(value[i]))
			return (1);
	}
	return (0);
}