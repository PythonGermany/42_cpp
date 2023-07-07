/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:57:15 by rburgsta          #+#    #+#             */
/*   Updated: 2023/03/06 14:57:15 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 private:
  std::string name;
  DiamondTrap();

 public:
  DiamondTrap(std::string name);
  DiamondTrap(DiamondTrap const& src);
  DiamondTrap& operator=(DiamondTrap const& rhs);
  ~DiamondTrap();

  void attack(const std::string& target);
  void whoAmI();
};

#endif