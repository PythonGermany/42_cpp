/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 05:28:42 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/09 05:28:42 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : n(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : n(N)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(Span const& rhs) : n(rhs.n)
{
	std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(Span const& rhs)
{
	std::cout << "Span copy assignment operator called" << std::endl;
	const_cast<size_t &>(n) = rhs.n;
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int nb)
{
	if (lst.size() >= n)
		throw std::exception();
	lst.push_front(nb);
}

int Span::shortestSpan()
{
	if (lst.size() < 2)
		throw std::exception();
	return (0);
}

int Span::longestSpan()
{
	if (lst.size() < 2)
		throw std::exception();
	return (0);
}