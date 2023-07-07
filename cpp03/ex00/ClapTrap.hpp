/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:44:02 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:37:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
 private:
  std::string name;
  int hit_points;
  int energy_points;
  int attack_damage;
  ClapTrap();

 public:
  ClapTrap(std::string name);
  ClapTrap(ClapTrap const& src);
  ClapTrap& operator=(ClapTrap const& rhs);
  ~ClapTrap();

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif