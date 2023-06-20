/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:35:13 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 23:35:13 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cerrno>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

typedef enum type_e { INVALID = -1, C, I, F, D } type_t;

typedef struct data_s {
  char c;
  int i;
  float f;
  double d;
} data_t;

class ScalarConverter {
 public:
  ScalarConverter();
  ScalarConverter(ScalarConverter const& rhs);
  ScalarConverter& operator=(ScalarConverter const& rhs);
  ~ScalarConverter();

  static void convert(std::string literal);
  static void printType(type_t type);
  static type_t verifyValue(std::string& value);

 private:
  static void printChar(char c, bool impossible);
  static void printInt(int i, bool impossible);
  static void printFloat(float f, bool impossible);
  static void printDouble(double d, bool impossible);
  static type_t checkPseudo(std::string& value);
  template <typename T, typename D>
  static bool overflow(T val, D min, D max);
  static bool intStringOverflow(std::string& str);
  template <typename T>
  static std::string valueToString(T val);
  static std::string removeTrailingZeros(std::string str);
};

#endif