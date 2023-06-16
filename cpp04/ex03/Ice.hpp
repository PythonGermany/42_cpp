/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:08:40 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:42:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "ICharacter.hpp"

class Ice : public AMateria {
 public:
  Ice();
  Ice(Ice const& src);
  Ice& operator=(Ice const& rhs);
  ~Ice();

  AMateria* clone() const;
  void use(ICharacter& target);
};

#endif