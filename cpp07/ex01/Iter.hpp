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
#define ITER_HPP

template <typename T, typename F>
void iter(T array[], int length, F f) {
  for (int i = 0; i < length; i++) f(array[i]);
}

#endif