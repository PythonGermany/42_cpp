/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:08:40 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:42:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "ICharacter.hpp"

class Cure : public AMateria {
 public:
  Cure();
  Cure(Cure const& src);
  Cure& operator=(Cure const& rhs);
  ~Cure();

  AMateria* clone() const;
  void use(ICharacter& target);
};

#endif