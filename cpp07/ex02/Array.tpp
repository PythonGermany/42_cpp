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
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : size(0)
{
	std::cout << "Array default constructor called" << std::endl;
	array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : size(n)
{
	std::cout << "Array constructor called" << std::endl;
	array = new T[n];
}

template <typename T>
Array<T>::Array(Array const& rhs)
{
	std::cout << "Array copy constructor called" << std::endl;
	*this = rhs;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& rhs)
{
	std::cout << "Array copy assignment operator called" << std::endl;
	T *temp = new T[rhs.size];
	for (int i = 0; i < rhs.size; i++)
		temp[i] = rhs.array[i];
	array = temp;
	this->size = rhs.size;
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor called" << std::endl;
	delete[] array;
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index >= size)
		throw std::exception();
	return (array[index]);
}

#endif