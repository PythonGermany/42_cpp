/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 03:17:08 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/08 03:17:08 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : arraySize(0), isAllocated(true) {
  std::cout << "Array default constructor called" << std::endl;
  array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : arraySize(n), isAllocated(true) {
  std::cout << "Array constructor called" << std::endl;
  array = new T[n];
}

template <typename T>
Array<T>::Array(Array const& rhs) : isAllocated(false) {
  std::cout << "Array copy constructor called" << std::endl;
  *this = rhs;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& rhs) {
  std::cout << "Array copy assignment operator called" << std::endl;
  if (this == &rhs) return (*this);
  T* temp = new T[rhs.arraySize];
  for (int i = 0; i < rhs.arraySize; i++) temp[i] = rhs.array[i];
  if (isAllocated == true) delete[] array;
  array = temp;
  isAllocated = true;
  this->arraySize = rhs.arraySize;
  return (*this);
}

template <typename T>
Array<T>::~Array() {
  std::cout << "Array destructor called" << std::endl;
  if (isAllocated) delete[] array;
}

template <typename T>
T& Array<T>::operator[](int index) {
  if (index < 0 || index >= arraySize) throw std::exception();
  return (array[index]);
}

template <typename T>
int Array<T>::size() const {
  return arraySize;
}

#endif