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

void ScalarConverter::convert(std::string literal) {
  data_t dt = {.type = verifyValue(literal)};
  printType(dt.type);
  if (dt.type == INVALID) return;
  if (dt.type == C) {
    dt.c = static_cast<char>(literal[1]);
    dt.i = static_cast<int>(dt.c);
    dt.d = static_cast<double>(dt.c);
    dt.f = static_cast<float>(dt.c);
  } else if (dt.type == D) {
    dt.d = std::atof(literal.c_str());
    dt.f = static_cast<float>(dt.d);
    dt.i = static_cast<int>(dt.d);
    dt.c = static_cast<char>(dt.d);
  }
  bool pseudo = checkPseudo(literal) != INVALID;
  bool precision = static_cast<int>(dt.d) != dt.d;
  bool tooSmall = (dt.d > 0 && dt.d < FLT_MIN) || (dt.d < 0 && dt.d > -FLT_MIN);
  printChar(dt.c, pseudo || precision || dt.d < CHAR_MIN || dt.d > CHAR_MAX);
  printInt(dt.i, pseudo || precision || dt.d < INT_MIN || dt.d > INT_MAX);
  printFloat(dt.f, !pseudo && (dt.d < -FLT_MAX || dt.d > FLT_MAX || tooSmall));
  printDouble(dt.d, !pseudo && (dt.d == INFINITY || dt.d == -INFINITY));
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

void ScalarConverter::printChar(char c, bool impossible) {
  std::cout << "char: ";
  if (impossible)
    std::cout << "impossible";
  else if (c >= '!' && c <= '~')
    std::cout << "\'" << c << "\'";
  else
    std::cout << "Non displayable";
  std::cout << std::endl;
}

void ScalarConverter::printInt(int i, bool impossible) {
  std::cout << "int: ";
  if (impossible)
    std::cout << "impossible";
  else
    std::cout << i;
  std::cout << std::endl;
}

void ScalarConverter::printFloat(float f, bool impossible) {
  std::cout << "float: ";
  if (impossible)
    std::cout << "impossible";
  else {
    std::cout << f;
    if (static_cast<int>(f) == f) std::cout << ".0";
    std::cout << "f";
  }
  std::cout << std::endl;
}

void ScalarConverter::printDouble(double d, bool impossible) {
  std::cout << "double: ";
  if (impossible)
    std::cout << "impossible";
  else {
    std::cout << d;
    if (static_cast<int>(d) == d) std::cout << ".0";
  }
  std::cout << std::endl;
}

type_t ScalarConverter::checkPseudo(std::string& value) {
  if (!value.compare("-inf") || !value.compare("+inf") || !value.compare("nan"))
    return (D);
  if (!value.compare("+inff") || !value.compare("-inff") ||
      !value.compare("nanf"))
    return (F);
  return (INVALID);
}

type_t ScalarConverter::verifyValue(std::string& value) {
  bool precisionFound = false;
  if (value.empty()) return (INVALID);
  if (value.length() == 3 && value[0] == '\'' && value[2] == '\'') return C;
  type_t pseudo = checkPseudo(value);
  if (pseudo != INVALID) return (pseudo);
  size_t length = value.length();
  bool hasSign = value[0] == '-' || value[0] == '+';
  bool maybeFloat = value[length - 1] == 'f';
  for (size_t i = 0; i < length; i++) {
    if (i == 0 && hasSign && length > 1)
      continue;
    else if (i == length - 1 && maybeFloat && i > 2 + hasSign)
      continue;
    else if (i != 0 && i != length - 1 - maybeFloat && !precisionFound &&
             value[i] == '.')
      precisionFound = true;
    else if (!std::isdigit(value[i]))
      return (INVALID);
  }
  if (value[value.length() - 1] == 'f') return (F);
  if (precisionFound) return (D);
  return (I);
}