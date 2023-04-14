/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:49:18 by rburgsta          #+#    #+#             */
/*   Updated: 2023/04/15 01:18:13 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src.name)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap default destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hit_points <= 0)
		std::cout << "ScavTrap " << name << " can't attack " << target 
		<< ". No health left!";
	else if (energy_points <= 0)
		std::cout << "ScavTrap " << name << " can't attack " << target 
		<< ". No energy left!";
	else
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing ";
		std::cout << attack_damage << " points of damage! " 
		<< --energy_points << " EP left!";
	}
	std::cout << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode!!!" << std::endl;
}