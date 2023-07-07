/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:24:34 by rburgsta          #+#    #+#             */
/*   Updated: 2023/02/17 17:24:34 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void min_test(Fixed& nb1, Fixed& nb2) {
  std::cout << "min(" << nb1 << ", " << nb2 << "): " << Fixed::min(nb1, nb2)
            << std::endl;
}

void max_test(Fixed& nb1, Fixed& nb2) {
  std::cout << "max(" << nb1 << ", " << nb2 << "): " << Fixed::max(nb1, nb2)
            << std::endl;
}

void min_const_test(Fixed const& nb1, Fixed const& nb2) {
  std::cout << "min(" << nb1 << ", " << nb2 << "): " << Fixed::min(nb1, nb2)
            << std::endl;
}

void max_const_test(Fixed const& nb1, Fixed const& nb2) {
  std::cout << "max(" << nb1 << ", " << nb2 << "): " << Fixed::max(nb1, nb2)
            << std::endl;
}

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << std::endl;
  std::cout << "\x1B[31mSubject tests:\x1B[0m" << std::endl;
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
  std::cout << std::endl;

  std::cout << "\x1B[31mIncrement/Decrement operator tests:\x1B[0m"
            << std::endl;
  std::cout << a << std::endl;
  std::cout << --a << std::endl;
  std::cout << a << std::endl;
  std::cout << a-- << std::endl;
  std::cout << a << std::endl;
  std::cout << std::endl;

  Fixed c(2.254f);
  Fixed d(0.99f);
  Fixed e(0.5f);
  Fixed f(1);

  a = Fixed(0.99f);
  std::cout << std::endl;
  std::cout << "\x1B[31mComparison operator tests:\x1B[0m" << std::endl;
  std::cout << a << " is equal to " << c << ": " << (a == c) << std::endl;
  std::cout << a << " is not equal to " << c << ": " << (a != c) << std::endl;
  std::cout << a << " is smaller than " << c << ": " << (a < c) << std::endl;
  std::cout << a << " is greater than " << c << ": " << (a > c) << std::endl;
  std::cout << a << " is equal to / smaller than " << c << ": " << (a <= c)
            << std::endl;
  std::cout << a << " is equal to / greater than " << c << ": " << (a >= c)
            << std::endl;
  std::cout << a << " is equal to / smaller than " << d << ": " << (a <= d)
            << std::endl;
  std::cout << a << " is equal to / greater than " << d << ": " << (a >= d)
            << std::endl;
  std::cout << std::endl;

  std::cout << "\x1B[31m+; -; *; / tests\x1B[0m" << std::endl;
  std::cout << a << " + " << c << " = " << (a + c) << std::endl;
  std::cout << a << " + " << c << " + " << e << " = " << (a + c + e)
            << std::endl;
  std::cout << a << " - " << c << " = " << (a - c) << std::endl;
  std::cout << c << " - " << a << " = " << (c - a) << std::endl;
  std::cout << a << " * " << c << " = " << (a * c) << std::endl;
  std::cout << a << " / " << c << " = " << (a / c) << std::endl;
  std::cout << c << " / " << a << " = " << (c / a) << std::endl;
  std::cout << e << "/" << e << " = " << (e / e) << std::endl;
  std::cout << e << "*" << e << " = " << (e * e) << std::endl;
  std::cout << e << " * 3 / " << e << " = " << (e * 3 / e) << std::endl;
  std::cout << e << " * 3 * " << e << " = " << (e * 3 * e) << std::endl;
  std::cout << f << " / 3 * " << 3 << " = " << (f / 3 * 3) << std::endl;
  std::cout << e << " * 3 / 2 * " << e
            << " * 3 / 2 = " << ((e * 3 / 2) * (e * 3 / 2)) << std::endl;
  std::cout << std::endl;

  std::cout << "\x1B[31mMin/Max tests:\x1B[0m" << std::endl;
  min_test(a, c);
  min_test(a, d);
  max_test(a, c);
  max_test(a, d);
  min_const_test(a, c);
  min_const_test(a, d);
  max_const_test(a, c);
  max_const_test(a, d);
  std::cout << std::endl;

  return 0;
}