/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:14:39 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:39:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
  FragTrap ft("Bob");
  ScavTrap st("Peter");
  DiamondTrap dt("Julian");

  std::cout << std::endl << "\x1B[31mFragTrap:\x1B[0m" << std::endl;
  ft.takeDamage(4);
  ft.takeDamage(5);
  ft.beRepaired(14);
  ft.attack("Tom");
  for (size_t i = 0; i < 9; i++) ft.attack("John");
  ft.beRepaired(15);
  ft.takeDamage(18);
  ft.beRepaired(15);
  ft.attack("John");
  ft.highFivesGuys();

  std::cout << std::endl << "\x1B[31mScavTrap:\x1B[0m" << std::endl;
  st.takeDamage(4);
  st.takeDamage(5);
  st.beRepaired(14);
  st.attack("Tom");
  for (size_t i = 0; i < 9; i++) st.attack("John");
  st.beRepaired(15);
  st.takeDamage(18);
  st.beRepaired(15);
  st.attack("John");
  st.guardGate();

  std::cout << std::endl << "\x1B[31mDiamondTrap:\x1B[0m" << std::endl;
  dt.attack("Bob");
  dt.takeDamage(10);
  dt.beRepaired(10);
  dt.guardGate();
  dt.highFivesGuys();
  dt.whoAmI();
  std::cout << std::endl;
  return (0);
}