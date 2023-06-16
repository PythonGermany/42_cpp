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
  int n = 3;
  Zombie* z = zombieHorde(n, "zombieHorde");

  for (int i = 0; i < n; i++) z[i].announce();
  delete[] z;
}
