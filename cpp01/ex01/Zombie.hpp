/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:34:59 by rburgsta          #+#    #+#             */
/*   Updated: 2022/12/15 19:34:59 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
 private:
  std::string name;

 public:
  Zombie();
  ~Zombie();

  void setName(std::string name);
  void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif