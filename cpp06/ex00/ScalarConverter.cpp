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
  type_t type = verifyValue(literal);
  if (type == INVALID) return;
  bool fail = false;
  data_t dt;
  if (type == C)
    dt = cast(literal[1]);
  else if (type == I) {
    dt = cast(std::atoi(literal.c_str()));
    fail = intStringOverflow(literal);
  } else if (type == F) {
    dt = cast(std::strtof(literal.c_str(), NULL));
    fail = errno == ERANGE;
  } else if (type == D) {
    dt = cast(std::strtod(literal.c_str(), NULL));
    fail = errno == ERANGE;
  }
  bool pseudo = checkPseudo(literal) != INVALID;
  long comp = std::atol(literal.c_str());
  printChar(dt.c, pseudo || overflow<char>(comp, CHAR_MIN, CHAR_MAX));
  printInt(dt.i, pseudo || overflow(comp, INT_MIN, INT_MAX) ||
                     (type == F && dt.f == 2147483648.0f) || fail);
  printFloat(dt.f,
             (!pseudo && (dt.f == INFINITY || dt.f == -INFINITY)) || fail);
  printDouble(dt.d, fail);
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
  bool prec = false;
  if (value.empty()) return (INVALID);
  size_t length = value.length();
  if (length == 3 && value[0] == '\'' && value[2] == '\'') return C;
  type_t pseudo = checkPseudo(value);
  if (pseudo != INVALID) return (pseudo);
  bool hasSign = value[0] == '-';
  bool maybeFloat = value[length - 1] == 'f';
  for (size_t i = 0; i < length; i++) {
    if (i == 0 && hasSign && length > 1)
      continue;
    else if (i == length - 1 && maybeFloat && i > 2 + hasSign &&
             value.find('.') != std::string::npos)
      continue;
    else if (i != 0 && i != length - 1 - maybeFloat && !prec && value[i] == '.')
      prec = true;
    else if (!std::isdigit(value[i]))
      return (INVALID);
  }
  if (value[length - 1] == 'f') return (F);
  if (prec) return (D);
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
    std::cout << removeTrailingZeros(valueToString<float>(f)) << "f";
  std::cout << std::endl;
}

void ScalarConverter::printDouble(double d, bool impossible) {
  std::cout << "double: ";
  if (impossible)
    std::cout << "impossible";
  else
    std::cout << removeTrailingZeros(valueToString<double>(d));
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

template <typename T>
bool ScalarConverter::overflow(long val, T min, T max) {
  return (val < static_cast<long>(min) || val > static_cast<long>(max));
}

template <typename T>
data_t ScalarConverter::cast(T val) {
  data_t data = {static_cast<char>(val), static_cast<int>(val),
                 static_cast<float>(val), static_cast<double>(val)};
  return data;
}

template <typename T>
std::string ScalarConverter::valueToString(T val) {
  std::stringstream ss;
  ss << std::fixed << std::setprecision(std::numeric_limits<T>::digits10 + 1)
     << val << std::scientific;
  return ss.str();
}

bool ScalarConverter::intStringOverflow(std::string& str) {
  if (str.empty()) return false;
  if (str[0] == '-') {
    if (str.size() > static_cast<size_t>(11)) return true;
    if (str.size() < static_cast<size_t>(11)) return false;
    if (str.compare("-2147483648") > 0) return true;
    return false;
  }
  if (str.size() > static_cast<size_t>(10)) return true;
  if (str.size() < static_cast<size_t>(10)) return false;
  if (str.compare("2147483647") > 0) return true;
  return false;
}

std::string ScalarConverter::removeTrailingZeros(std::string str) {
  if (str.empty()) return str;
  while (str[str.length() - static_cast<size_t>(1)] == '0') {
    if (str.length() < static_cast<size_t>(2) || str[str.length() - 2] == '.')
      break;
    str.erase(str.length() - static_cast<size_t>(1), static_cast<size_t>(1));
  }
  return str;
}