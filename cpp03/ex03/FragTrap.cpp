/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:49:18 by rburgsta          #+#    #+#             */
/*   Updated: 2023/03/06 16:01:41 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(FragTrap const& rhs)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap default destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (hit_points <= 0)
		std::cout << "FragTrap " << name << " can't attack " << target 
		<< ". No health left!";
	else if (energy_points <= 0)
		std::cout << "FragTrap " << name << " can't attack " << target 
		<< ". No energy left!";
	else
	{
		std::cout << "FragTrap " << name << " attacks " << target << ", causing ";
		std::cout << attack_damage << " points of damage! " 
		<< --energy_points << " EP left!";
	}
	std::cout << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High five?" << std::endl;
}