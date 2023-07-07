/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:55:13 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/30 16:55:13 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <map>
# include <string>

# define DATABASE_LOC "cpp_09/data.csv"

class BitcoinExchange
{
private:
	std::string inputPath;
	std::ifstream input;
	std::ifstream database;
	std::map<std::string, float> data;
public:
	BitcoinExchange();
	BitcoinExchange(std::string inputLoc);
	BitcoinExchange(BitcoinExchange const& rhs);
	BitcoinExchange& operator=(BitcoinExchange const& rhs);
	~BitcoinExchange();

	static void handleError(std::string msg, int code);
};

#endif