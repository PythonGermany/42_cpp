/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:36:22 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 23:36:22 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization() {}

Serialization::Serialization(Serialization const& rhs) { *this = rhs; }

Serialization& Serialization::operator=(Serialization const& rhs) {
  if (this == &rhs) return (*this);
  return (*this);
}

Serialization::~Serialization() {}

uintptr_t Serialization::serialize(Data* ptr) {
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialization::deserialize(uintptr_t raw) {
  return (reinterpret_cast<Data*>(raw));
}