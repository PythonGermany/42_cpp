/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:59:39 by rburgsta          #+#    #+#             */
/*   Updated: 2022/12/17 21:59:39 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(&weapon), name(name)
{
   std::cout << "HumanA '" << this->name << "' is being created" << std::endl;
}

HumanA::~HumanA(void)
{
   std::cout << "HumanA '" << this->name << "' is being deleted" << std::endl;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}
