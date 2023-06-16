/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:40:34 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:42:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : name("NONAME"), mat_on_floor(0) {
  std::cout << "Character default constructor called" << std::endl;
  floor = new AMateria*[mat_on_floor];
  for (size_t i = 0; i < 4; i++) materia[i] = NULL;
}

Character::Character(std::string name) : name(name), mat_on_floor(0) {
  std::cout << "Character name constructor called" << std::endl;
  floor = new AMateria*[mat_on_floor];
  for (size_t i = 0; i < 4; i++) materia[i] = NULL;
}

Character::Character(Character const& src) {
  std::cout << "Character copy constructor called" << std::endl;
  *this = src;
}

Character& Character::operator=(Character const& rhs) {
  std::cout << "Character copy assignment operator called" << std::endl;
  name = rhs.name;
  for (size_t i = 0; i < 4; i++) {
    if (materia[i] != NULL) delete materia[i];
    materia[i] = NULL;
    if (rhs.materia[i] != NULL) materia[i] = rhs.materia[i]->clone();
  }
  return (*this);
}

Character::~Character(void) {
  std::cout << "Character destructor called" << std::endl;
  for (size_t i = 0; i < 4; i++)
    if (materia[i] != NULL) delete materia[i];
  for (int i = 0; i < mat_on_floor; i++) delete floor[i];
  delete[] floor;
}

std::string const& Character::getName() const { return (name); }

void Character::equip(AMateria* m) {
  for (size_t i = 0; i < 4; i++) {
    if (materia[i] == NULL) {
      materia[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4 && materia[idx] != NULL) {
    AMateria** tmp_floor = new AMateria*[mat_on_floor + 1];
    for (int i = 0; i < mat_on_floor; i++) tmp_floor[i] = floor[i];
    tmp_floor[mat_on_floor++] = materia[idx];
    materia[idx] = NULL;
    delete[] floor;
    floor = tmp_floor;
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx < 4 && materia[idx] != NULL) materia[idx]->use(target);
}