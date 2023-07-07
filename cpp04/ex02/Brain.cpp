/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:02:39 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:41:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
  std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const& src) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = src;
}

Brain& Brain::operator=(Brain const& rhs) {
  std::cout << "Brain copy assignment operator called" << std::endl;
  for (size_t i = 0; i < 100; i++) this->ideas[i] = rhs.ideas[i];
  return (*this);
}

Brain::~Brain(void) { std::cout << "Brain destructor called" << std::endl; }

void Brain::addIdea(const unsigned int index, const std::string& idea) {
  if (index < 100) ideas[index] = idea;
}

void Brain::readIdea(const unsigned index) {
  if (index < 100) std::cout << "Idea: " << ideas[index] << std::endl;
}