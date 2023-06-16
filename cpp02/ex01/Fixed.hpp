/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:02:24 by rburgsta          #+#    #+#             */
/*   Updated: 2023/02/17 16:02:24 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 private:
  int number;
  static const int fractionalBits;

 public:
  Fixed();
  Fixed(const int nb);
  Fixed(const float nb);
  Fixed(Fixed const& src);
  Fixed& operator=(Fixed const& rhs);
  ~Fixed();

  void setRawBits(int const raw);
  int getRawBits(void) const;

  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, Fixed const& rhs);

#endif