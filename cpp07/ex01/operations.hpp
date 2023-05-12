/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 07:30:58 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/12 07:36:59 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_HPP
# define OPERATIONS_HPP

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
	if (a >= 'a' && a <= 'z')
		a -= 'a' - 'A';
}

#endif