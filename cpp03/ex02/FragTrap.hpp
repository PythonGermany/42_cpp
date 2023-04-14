/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:04:45 by rburgsta          #+#    #+#             */
/*   Updated: 2023/04/14 15:03:34 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	FragTrap();
public:
	FragTrap(std::string name);
	FragTrap(FragTrap const& src);
	FragTrap& operator=(FragTrap const& rhs);
	~FragTrap();

	void highFivesGuys(void);
};

#endif