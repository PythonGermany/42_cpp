/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:10:16 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:42:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
  std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const& src) : AMateria(src) {
  std::cout << "Ice copy constructor called" << std::endl;
  *this = src;
}

Ice& Ice::operator=(Ice const& rhs) {
  std::cout << "Ice copy assignment operator called" << std::endl;
  (void)rhs;
  return (*this);
}

Ice::~Ice(void) { std::cout << "Ice destructor called" << std::endl; }

AMateria* Ice::clone() const { return (new Ice()); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}