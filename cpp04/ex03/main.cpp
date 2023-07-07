/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:31:05 by rburgsta          #+#    #+#             */
/*   Updated: 2023/04/19 17:14:30 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <cstdio>

int main()
{
	IMateriaSource *src = new MateriaSource();
	AMateria *ltmp;
	ltmp = new Ice();
	src->learnMateria(ltmp);
	delete ltmp;
	ltmp = new Cure();
	src->learnMateria(ltmp);
	delete ltmp;
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	//system("leaks ex03");
	return 0;
}