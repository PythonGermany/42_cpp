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
  Zombie(std::string name);
  ~Zombie();

  void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif