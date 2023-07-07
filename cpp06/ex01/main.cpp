/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:12:21 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/12 14:12:21 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serialization.hpp"

void comparePointers(Data *a, Data *b) {
  if (a == b)
    std::cout << "Pointers are equal: " << a << " = " << b;
  else
    std::cout << "Pointers are NOT equal" << a << " != " << b;
  std::cout << std::endl;
}

int main() {
  Serialization s;
  Data d = {251};
  Data d2 = {631};
  uintptr_t dintptr = s.serialize(&d);
  Data *dptr = s.deserialize(dintptr);

  comparePointers(dptr, &d);
  comparePointers(dptr, &d2);
  return (0);
}