/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:42:29 by rburgsta          #+#    #+#             */
/*   Updated: 2023/03/08 19:47:17 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	b = new Brain();
}

Cat::Cat(Cat const& src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat& Cat::operator=(Cat const& rhs)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = rhs.type;
	this->b = new Brain(*rhs.b);
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete b;
}

void Cat::makeSound(void) const
{
	std::cout << "Meaaaaoowwwwwww" << std::endl;
}