/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:57:12 by rburgsta          #+#    #+#             */
/*   Updated: 2023/03/06 14:57:12 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	this->name = rhs.name;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	FragTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am the DiamondTrap " << name 
	<< " and I inherit from the ClapTrap " << ClapTrap::name << "!" << std::endl; 
}