/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:45:50 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:38:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : hit_points(10), energy_points(10), attack_damage(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name), hit_points(10), energy_points(10), attack_damage(0) {
  std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& src) {
  std::cout << "ClapTrap copy constructor called" << std::endl;
  *this = src;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
  std::cout << "ClapTrap copy assignment operator called" << std::endl;
  this->name = rhs.name;
  this->hit_points = rhs.hit_points;
  this->energy_points = rhs.energy_points;
  this->attack_damage = rhs.attack_damage;
  return (*this);
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (hit_points <= 0)
    std::cout << "ClapTrap " << name << " can't attack " << target
              << ". No health left!";
  else if (energy_points <= 0)
    std::cout << "ClapTrap " << name << " can't attack " << target
              << ". No energy left!";
  else {
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing ";
    std::cout << attack_damage << " points of damage! " << --energy_points
              << " EP left!";
  }
  std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hit_points > 0) {
    if (amount > (unsigned int)hit_points) amount = hit_points;
    hit_points -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount;
    std::cout << " points of damage! " << hit_points << " HP left!";
  } else
    std::cout << "ClapTrap " << name
              << " can't take damage. It is already at 0 HP!";
  std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hit_points <= 0)
    std::cout << "ClapTrap " << name << " can't be repaired. No health left!";
  else if (energy_points <= 0)
    std::cout << "ClapTrap " << name << " can't be repaired. No energy left!";
  else {
    hit_points += amount;
    std::cout << "ClapTrap " << name << " gained " << amount << " HP! ";
    std::cout << "It now has " << hit_points << " HP and " << --energy_points
              << " EP left!";
  }
  std::cout << std::endl;
}