/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:25:11 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:39:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  delete meta;
  delete j;
  delete i;
  std::cout << std::endl;
  const WrongAnimal *wrongmeta = new WrongAnimal();
  const WrongAnimal *wrongi = new WrongCat();
  std::cout << wrongi->getType() << " " << std::endl;
  wrongi->makeSound();
  wrongmeta->makeSound();
  delete wrongmeta;
  delete wrongi;
  // system("leaks ex00");
  return 0;
}