/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:36:22 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 23:36:22 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Template.hpp"

Template::Template()
{
	std::cout << "Template default constructor called" << std::endl;
}

Template::Template(Template const& rhs)
{
	std::cout << "Template copy constructor called" << std::endl;
	*this = rhs;
}

Template& Template::operator=(Template const& rhs)
{
	std::cout << "Template copy assignment operator called" << std::endl;
	
	return (*this);
}

Template::~Template()
{
	std::cout << "Template destructor called" << std::endl;
}
