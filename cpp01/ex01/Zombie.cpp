/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:34:04 by rburgsta          #+#    #+#             */
/*   Updated: 2022/12/17 15:34:04 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) { std::cout << "Zombie is being created" << std::endl; }

Zombie::~Zombie(void) {
  std::cout << "Zombie '" << this->name << "' is being deleted" << std::endl;
}

void Zombie::setName(std::string name) { this->name = name; }

void Zombie::announce(void) {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
