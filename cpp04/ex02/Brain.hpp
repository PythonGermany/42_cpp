/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:59:52 by rburgsta          #+#    #+#             */
/*   Updated: 2023/04/14 17:45:03 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(Brain const& rhs);
	Brain& operator=(Brain const& src);
	~Brain();

	void addIdea(const unsigned int index, const std::string& idea);
	void readIdea(const unsigned index);
};

#endif