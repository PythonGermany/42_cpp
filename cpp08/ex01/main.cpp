/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 07:55:26 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/09 07:55:26 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>

#include <iostream>

#include "Span.hpp"

int main() {
  srand(time(NULL));

  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp.longestSpan() << std::endl << std::endl;

  Span sp2(sp);
  std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp2.longestSpan() << std::endl << std::endl;

  Span sp3(20000);
  try {
    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  for (int i = 0; i < 20000; i++) sp3.addNumber(i);
  try {
    sp3.addNumber(rand());
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp3.longestSpan() << std::endl << std::endl;

  Span sp4(50000);
  for (int i = 0; i < 50000; i++) sp4.addNumber(rand());
  std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp4.longestSpan() << std::endl << std::endl;

  Span sp5(50000);
  std::vector<int> vec(25000, 0);
  std::generate(vec.begin(), vec.end(), rand);
  try {
    sp5.addRange(vec.begin(), vec.end());
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
  vec.push_back(rand());
  std::generate(vec.begin(), vec.end(), rand);
  try {
    sp5.addRange(vec.begin(), vec.end());
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp5.longestSpan() << std::endl << std::endl;
  return 0;
}