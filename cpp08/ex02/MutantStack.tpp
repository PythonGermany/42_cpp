/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:40:05 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/12 17:40:05 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const& rhs) {
  *this = rhs;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const& rhs) {
  std::stack<T>::operator=(rhs);
  return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::iterator::iterator() {}

template <typename T>
MutantStack<T>::iterator::iterator(int index, MutantStack<T>& stack)
    : index(index), stack(stack) {}

template <typename T>
MutantStack<T>::iterator::iterator(iterator const& rhs) : stack(rhs.stack) {
  *this = rhs;
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator=(
    iterator const& rhs) {
  if (this == &rhs) return (*this);
  std::iterator<std::bidirectional_iterator_tag, T>::operator=(rhs);
  index = rhs.index;
  stack = rhs.stack;
  return (*this);
}

template <typename T>
MutantStack<T>::iterator::~iterator() {}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++() {
  ++index;
  return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int) {
  MutantStack<T>::iterator temp = *this;
  index++;
  return (temp);
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--() {
  --index;
  return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int) {
  MutantStack<T>::iterator temp = *this;
  index--;
  return (temp);
}

template <typename T>
T& MutantStack<T>::iterator::operator*() {
  return (stack.c.at(index));
}

template <typename T>
T* MutantStack<T>::iterator::operator->() {
  return (&stack.c.at(index));
}

template <typename T>
bool MutantStack<T>::iterator::operator==(iterator const& rhs) const {
  return (stack == rhs.stack && index == rhs.index);
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(iterator const& rhs) const {
  return !(*this == rhs);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return (iterator(0, *this));
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
  return (iterator(this->size(), *this));
}

#endif