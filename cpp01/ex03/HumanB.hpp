/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:57:46 by rburgsta          #+#    #+#             */
/*   Updated: 2022/12/17 22:57:46 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanB {
 private:
  Weapon* weapon;
  std::string name;

 public:
  HumanB(std::string name);
  ~HumanB();

  void attack(void);
  void setWeapon(Weapon& weapon);
};

#endif
