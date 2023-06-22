/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:34:23 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/07 21:34:23 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

int main() {
  int aCount = 0, bCount = 0, cCount = 0;
  for (int i = 0; i < 1000; i++) {
    Base *b = generate();
    identify(b);
    identify(*b);
    if (dynamic_cast<A *>(b) != NULL)
      aCount++;
    else if (dynamic_cast<B *>(b) != NULL)
      bCount++;
    else if (dynamic_cast<C *>(b) != NULL)
      cCount++;
    delete b;
  }
  A *a = new A();
  B *b = new B();
  C *c = new C();

  std::cout << aCount << " " << bCount << " " << cCount << std::endl;
  identify(a);
  identify(b);
  identify(c);
  identify(*a);
  identify(*b);
  identify(*c);
}