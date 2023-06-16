/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 05:28:42 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/09 05:28:42 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : n(0) {}

Span::Span(unsigned int N) : n(N) {}

Span::Span(Span const& rhs) : n(rhs.n) { *this = rhs; }

Span& Span::operator=(Span const& rhs) {
  vec.resize(rhs.vec.size());
  std::copy(rhs.vec.begin(), rhs.vec.end(), vec.begin());
  const_cast<unsigned int&>(n) = rhs.n;
  return (*this);
}

Span::~Span() {}

void Span::addNumber(int nb) {
  if (vec.size() >= n) throw std::exception();
  vec.insert(std::upper_bound(vec.begin(), vec.end(), nb), nb);
}

int Span::shortestSpan() {
  int min_span = INT_MAX;
  if (vec.size() < 2) throw std::exception();
  for (size_t i = 0; i < vec.size() - 1; i++)
    if (vec[i + 1] - vec[i] < min_span) min_span = vec[i + 1] - vec[i];
  return (min_span);
}

int Span::longestSpan() {
  if (vec.size() < 2) throw std::exception();
  return (vec[vec.size() - 1] - vec[0]);
}