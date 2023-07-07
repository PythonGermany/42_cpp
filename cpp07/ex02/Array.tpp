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

# include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0)
{
	std::cout << "Array default constructor called" << std::endl;
	array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
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
	T *temp = new T[rhs._size];
	for (int i = 0; i < rhs._size; i++)
		temp[i] = rhs.array[i];
	//if (array != NULL) //HOW to differenciate between array allocated and uninitialized?
	//	delete[] array;
	array = temp;
	this->_size = rhs._size;
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
	if (index < 0 || index >= _size)
		throw std::exception();
	return (array[index]);
}

template <typename T>
int Array<T>::size() const
{
	return _size;
}

#endif