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

bool overflow(long int val, long int min, long int max) {
  return (val < min || val > max);
}

void ScalarConverter::convert(std::string literal) {
  data_t dt = {.type = verifyValue(literal)};
  if (dt.type == INVALID) return;
  if (dt.type == C) {
    dt.c = static_cast<char>(literal[1]);
    dt.i = static_cast<int>(dt.c);
    dt.f = static_cast<float>(dt.c);
    dt.d = static_cast<double>(dt.c);
  } else if (dt.type == I) {
    dt.i = std::atoi(literal.c_str());
    dt.c = static_cast<char>(dt.i);
    dt.f = static_cast<float>(dt.i);
    dt.d = static_cast<double>(dt.i);
  } else if (dt.type == F) {
    dt.f = std::strtof(literal.c_str(), NULL);
    dt.c = static_cast<char>(dt.f);
    dt.i = static_cast<int>(dt.f);
    dt.d = static_cast<double>(dt.f);
  } else if (dt.type == D) {
    dt.d = std::strtod(literal.c_str(), NULL);
    dt.c = static_cast<char>(dt.d);
    dt.i = static_cast<int>(dt.d);
    dt.f = static_cast<float>(dt.d);
  }
  bool pseudo = checkPseudo(literal) != INVALID;
  long int comp = std::atol(literal.c_str());
  printChar(dt.c, pseudo || comp < static_cast<long int>(CHAR_MIN) ||
                      comp > static_cast<long int>(CHAR_MAX));
  printInt(dt.i, pseudo || comp < static_cast<long int>(INT_MIN) ||
                     static_cast<long int>(comp > INT_MAX));
  printFloat(dt.f, errno == ERANGE);
  printDouble(dt.d, errno == ERANGE);
  errno = 0;
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
  type_t pseudo = checkPseudo(value);
  if (pseudo != INVALID) return (pseudo);
  size_t length = value.length();
  bool hasSign = value[0] == '-' || value[0] == '+';
  bool maybeFloat = value[length - 1] == 'f';
  for (size_t i = 0; i < length; i++) {
    if (i == 0 && hasSign && length > 1)
      continue;
    else if (i == length - 1 && maybeFloat && i > 2 + hasSign &&
             value.find('.') != std::string::npos)
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
  else
    std::cout << std::fixed << f << "f";
  std::cout << std::scientific << std::endl;
}

void ScalarConverter::printDouble(double d, bool impossible) {
  std::cout << "double: ";
  if (impossible)
    std::cout << "impossible";
  else
    std::cout << std::fixed << d;
  std::cout << std::scientific << std::endl;
}

type_t ScalarConverter::checkPseudo(std::string& value) {
  if (!value.compare("-inf") || !value.compare("+inf") || !value.compare("nan"))
    return (D);
  if (!value.compare("+inff") || !value.compare("-inff") ||
      !value.compare("nanf"))
    return (F);
  return (INVALID);
}