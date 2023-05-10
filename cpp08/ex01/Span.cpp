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

Span::Span() : n(0) , min_span(INT_MAX)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : n(N) , min_span(INT_MAX)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(Span const& rhs) : n(rhs.n)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = rhs;
}

Span& Span::operator=(Span const& rhs)
{
	std::cout << "Span copy assignment operator called" << std::endl;
	vec = std::vector<int>(rhs.vec.size());
	std::copy(rhs.vec.begin(), rhs.vec.end(), vec.begin());
	const_cast<size_t &>(n) = rhs.n;
	min_span = rhs.min_span;
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int nb)
{
	if (vec.size() >= n)
		throw std::exception();
	vec.insert(std::upper_bound(vec.begin(), vec.end(), nb), nb);
}

int Span::shortestSpan()
{
	int min_span = INT_MAX;
	if (vec.size() < 2)
		throw std::exception();
	for (size_t i = 0; i < vec.size() - 1; i++)
		if (vec[i + 1] - vec[i] < min_span)
			min_span = vec[i + 1] - vec[i];
	return (min_span);
}

int Span::longestSpan()
{
	if (vec.size() < 2)
		throw std::exception();
	return (vec[vec.size() - 1] - vec[0]);
}

void Span::printSpan()
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}