/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:40:34 by rburgsta          #+#    #+#             */
/*   Updated: 2023/03/09 18:12:07 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		materia[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
	std::cout << "Character name constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		materia[i] = NULL;
}

Character::Character(Character const& src)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

Character& Character::operator=(Character const& rhs)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	return (*this);
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		if (materia[i] != NULL)
			delete materia[i];
}

std::string const& Character::getName() const
{
	return (name);
}

void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (materia[i] == NULL)
		{
			materia[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && materia[idx] != NULL)
		materia[idx] == NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && materia[idx] != NULL)
		materia[idx]->use(target);
}