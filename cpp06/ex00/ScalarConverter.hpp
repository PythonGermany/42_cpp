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

#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>

typedef enum type_e { INVALID = -1, C, I, F, D } type_t;

class ScalarConverter {
 public:
  ScalarConverter();
  ScalarConverter(ScalarConverter const& rhs);
  ScalarConverter& operator=(ScalarConverter const& rhs);
  ~ScalarConverter();

  static void convert(std::string literal);

 private:
  static void printType(type_t type);
  static type_t verifyValue(std::string& value);
};

#endif