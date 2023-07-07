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
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#define DATABASE_LOC "cpp_09/data.csv"

class BitcoinExchange {
 private:
  std::string inputPath;
  std::ifstream input;
  std::ifstream database;
  std::map<std::string, float> data;

 public:
  BitcoinExchange();
  BitcoinExchange(std::string inputLoc);
  BitcoinExchange(BitcoinExchange const &rhs);
  BitcoinExchange &operator=(BitcoinExchange const &rhs);
  ~BitcoinExchange();

  void processInput();
  float calculateValue(std::string &date, float amount);
  static void handleError(std::string msg, int exitCode);
  static void handleError(std::string msg);

 private:
  int verifyDate(std::string &date);
  int verifyValue(std::string &value);
};

#endif