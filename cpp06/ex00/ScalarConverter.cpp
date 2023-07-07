/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:36:22 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 23:36:22 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const& rhs) { *this = rhs; }

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs) {
  if (this == &rhs) return (*this);
  return (*this);
}

ScalarConverter::~ScalarConverter() {}

void printChar(char c, bool impossible) {
  std::cout << "char: ";
  if (impossible)
    std::cout << "impossible";
  else if (c >= '!' && c <= '~')
    std::cout << "\'" << c << "\'";
  else
    std::cout << "Non displayable";
  std::cout << std::endl;
}

void printInt(int i, bool impossible) {
  std::cout << "int: ";
  if (impossible)
    std::cout << "impossible";
  else
    std::cout << i;
  std::cout << std::endl;
}

void printFloat(float f, bool impossible) {
  std::cout << "float: ";
  if (impossible)
    std::cout << "impossible";
  else
    std::cout << f << "f";
  std::cout << std::endl;
}

void printDouble(double d, bool impossible) {
  std::cout << "double: ";
  if (impossible)
    std::cout << "impossible";
  else
    std::cout << d;
  std::cout << std::endl;
}

typedef struct data_s {
  type_t type;
  char c;
  int i;
  float f;
  double d;
} data_t;

void ScalarConverter::convert(std::string literal) {
  data_t dt = {.type = verifyValue(literal)};
  printType(dt.type);
  if (dt.type == INVALID) return;
  if (dt.type == C) {
    dt.c = static_cast<char>(literal[1]);
    dt.i = static_cast<int>(dt.c);
    dt.d = static_cast<double>(dt.c);
    dt.f = static_cast<float>(dt.c);
  } else {
    dt.d = std::atof(literal.c_str());
    dt.f = static_cast<float>(dt.d);
    dt.i = static_cast<int>(dt.d);
    dt.c = static_cast<char>(dt.d);
  }
  bool pseudo =
      dt.d == INFINITY || dt.d == -INFINITY || dt.d == NAN || dt.d == -NAN;
  bool precision = static_cast<int>(dt.d) != dt.d;
  bool tooPrecise =
      (dt.d > 0 && dt.d < __FLT_MIN__) || (dt.d < 0 && dt.d > -__FLT_MIN__);
  printChar(dt.c, pseudo || precision || dt.d < CHAR_MIN || dt.d > CHAR_MAX);
  printInt(dt.i, pseudo || precision || dt.d < INT_MIN || dt.d > INT_MAX);
  printFloat(dt.f, !pseudo && (dt.d < -__FLT_MAX__ || dt.d > __FLT_MAX__ ||
                               tooPrecise));
  printDouble(dt.d, false);
}

void ScalarConverter::printType(type_t type) {
  std::cout << "Type: ";
  if (type == C)
    std::cout << "char";
  else if (type == I)
    std::cout << "int";
  else if (type == F)
    std::cout << "float";
  else if (type == D)
    std::cout << "double";
  else
    std::cout << "INVALID";
  std::cout << std::endl;
}

type_t ScalarConverter::verifyValue(std::string& value) {
  bool precisionFound = false;
  if (value.empty()) return (INVALID);
  if (value.length() == 3 && value[0] == '\'' && value[2] == '\'') return C;
  if (!value.compare("-inf") || !value.compare("+inf") || !value.compare("nan"))
    return (D);
  if (!value.compare("+inff") || !value.compare("-inff") ||
      !value.compare("nanf"))
    return (F);
  size_t length = value.length();
  bool hasSign = value[0] == '-' || value[0] == '+';
  bool isFloat = value[length - 1] == 'f';
  for (size_t i = 0; i < length; i++) {
    if (i == 0 && hasSign && length > 1)  // Sign validation
      continue;
    else if (i == length - 1 && isFloat && i > 2 + hasSign)  // Float validation
      continue;
    else if (i != 0 && i != length - 1 - isFloat && !precisionFound &&
             value[i] == '.')  // Precision validation
      precisionFound = true;
    else if (!std::isdigit(value[i]))
      return (INVALID);
  }
  if (value[value.length() - 1] == 'f') return (F);
  if (precisionFound) return (D);
  return (I);
}