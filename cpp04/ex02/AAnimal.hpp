/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:26:03 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:41:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
 protected:
  std::string type;

 public:
  AAnimal();
  AAnimal(AAnimal const& rhs);
  AAnimal& operator=(AAnimal const& src);
  virtual ~AAnimal();

  virtual void makeSound() const = 0;
  std::string getType() const;
};

#endif