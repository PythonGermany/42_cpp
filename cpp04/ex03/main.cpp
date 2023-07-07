/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:31:05 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:42:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  IMateriaSource *src = new MateriaSource();
  AMateria *ltmp;
  ltmp = new Ice();
  src->learnMateria(ltmp);
  delete ltmp;
  ltmp = new Cure();
  src->learnMateria(ltmp);
  delete ltmp;
  ICharacter *me = new Character("me");
  std::cout << me->getName() << std::endl;
  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter *bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  me->unequip(0);
  delete bob;
  delete me;
  delete src;
  // system("leaks ex03");
  return 0;
}