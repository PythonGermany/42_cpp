/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:32:04 by rburgsta          #+#    #+#             */
/*   Updated: 2022/12/15 19:32:04 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
  Zombie z("Zomb");
  z.announce();
  Zombie *ptr = newZombie("newZombie");
  ptr->announce();
  randomChump("randomChump");
  delete ptr;
}
