/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:49:49 by rburgsta          #+#    #+#             */
/*   Updated: 2022/12/17 21:49:49 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
   this->type = type;
   std::cout << "Weapon '" << this->type << "' is being created" << std::endl;
}

Weapon::~Weapon(void)
{
   std::cout << "Weapon '" << this->type << "' is being deleted" << std::endl;
}

const std::string& Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
