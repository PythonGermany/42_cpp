/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:26:03 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:39:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
 protected:
  std::string type;

 public:
  Animal();
  Animal(Animal const& rhs);
  Animal& operator=(Animal const& src);
  virtual ~Animal();

  virtual void makeSound() const;
  std::string getType() const;
};

#endif