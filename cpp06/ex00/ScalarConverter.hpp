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

#include <float.h>

#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>

typedef enum type_e { INVALID = -1, C, I, F, D } type_t;

typedef struct data_s {
  type_t type;
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
};

#endif