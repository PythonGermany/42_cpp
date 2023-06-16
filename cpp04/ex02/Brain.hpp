/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:59:52 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:41:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
 private:
  std::string ideas[100];

 public:
  Brain();
  Brain(Brain const& rhs);
  Brain& operator=(Brain const& src);
  ~Brain();

  void addIdea(const unsigned int index, const std::string& idea);
  void readIdea(const unsigned index);
};

#endif