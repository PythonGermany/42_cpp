/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:10:00 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/08 01:10:00 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
T& min(T& a, T& b) {
  return (a < b ? a : b);
}

template <typename T>
T& max(T& a, T& b) {
  return (a > b ? a : b);
}

#endif