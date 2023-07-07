/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:32:48 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/08 20:32:48 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T container, int nb)
{
	typename T::iterator itr = std::find(container.begin(), container.end(), nb);
	if (itr == container.end())
		throw std::exception();
	return (itr);
}

#endif