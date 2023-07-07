/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:48:43 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:39:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
 protected:
  ScavTrap();

 public:
  ScavTrap(std::string name);
  ScavTrap(ScavTrap const& src);
  ScavTrap& operator=(ScavTrap const& rhs);
  ~ScavTrap();

  void attack(const std::string& target);
  void guardGate(void);
};

#endif