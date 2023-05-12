/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 02:27:15 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/08 02:27:15 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
	T *array;
	int _size;
public:
	Array();
	Array(unsigned int n);
	Array(Array const& rhs);
	Array& operator=(Array const& rhs);
	~Array();

	T& operator[](int index);
	int size() const;
};

# include "Array.tpp"

#endif