/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:53:51 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/12 14:53:51 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

Base* generate(void) {
  static bool first = false;
  if (first == false) {
    srand(time(NULL));
    first = true;
  }
  int index = rand() % 3;

  if (index == 0)
    return (new A());
  else if (index == 1)
    return (new B());
  else if (index == 2)
    return (new C());
  return (NULL);
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p) != NULL)
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p) != NULL)
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p) != NULL)
    std::cout << "C" << std::endl;
}

void identify(Base& p) {
  try {
    Base& temp = dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
    (void)temp;
    return;
  } catch (const std::exception& e) {
  }
  try {
    Base& temp = dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
    (void)temp;
    return;
  } catch (const std::exception& e) {
  }
  try {
    Base& temp = dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
    (void)temp;
  } catch (const std::exception& e) {
  }
}