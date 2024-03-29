/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:14:39 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:38:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
  ScavTrap st("Bob");

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
  return (0);
}