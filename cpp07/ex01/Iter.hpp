/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:27:53 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/08 01:27:53 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void print(T& a)
{
	std::cout << a << " ";
}

template <typename T>
void clear(T& a)
{
	a = 0;
}

template <typename T>
void pow(T& a)
{
	a *= a;
}

template <typename T>
void toUpper(T& a)
{
	if (typeid(a) == typeid(char))
	{
		if (a >= 'a' && a <= 'z')
			a -= 'a' - 'A';
	}
}

template <typename T>
void iter(T array[], int length, void (*f)(T&))
{
	for (int i = 0; i < length; i++)
		f(array[i]);
}

#endif