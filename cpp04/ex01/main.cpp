/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:25:11 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:40:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  size_t array_size = 4;
  Animal *a[array_size];
  size_t i = 0;

  std::cout << "\x1B[31mSubject construction:\x1B[0m" << std::endl;
  const Animal *j1 = new Dog();
  const Animal *i1 = new Cat();
  std::cout << std::endl << "\x1B[31mSubject destruction:\x1B[0m" << std::endl;
  delete j1;  // should not create a leak
  delete i1;

  std::cout << std::endl << "\x1B[31mConstruct array:\x1B[0m" << std::endl;
  for (; i < array_size / 2; i++) a[i] = new Dog();
  for (; i < array_size; i++) a[i] = new Cat();
  std::cout << std::endl << "\x1B[31mDelete arrray:\x1B[0m" << std::endl;
  while (i-- > 0) delete a[i];
  std::cout << std::endl
            << "\x1B[31mDog & Cat Construction:\x1B[0m" << std::endl;
  Dog x;
  Cat z;
  x.getBrain()->addIdea(0, "Idea one");
  std::cout << std::endl << "\x1B[31mDog & Cat Copy:\x1B[0m" << std::endl;
  Dog y(x);
  Cat c(z);
  x.getBrain()->addIdea(1, "Idea two");
  x.getBrain()->readIdea(0);
  x.getBrain()->readIdea(1);
  y.getBrain()->readIdea(0);
  y.getBrain()->readIdea(1);
  std::cout << "Brain one: " << x.getBrain() << std::endl;
  std::cout << "Brain two: " << y.getBrain() << std::endl;
  std::cout << std::endl
            << "\x1B[31mDog & Cat destruction:\x1B[0m" << std::endl;
  // system("leaks ex01");
  return 0;
}