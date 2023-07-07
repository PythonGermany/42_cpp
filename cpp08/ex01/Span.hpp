/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 05:28:54 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/09 05:28:54 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <climits>
# include <vector>
# include <algorithm>

class Span
{
private:
	std::vector<int> vec;
	const size_t n;
	int min_span;
public:
	Span();
	Span(unsigned int N);
	Span(Span const& rhs);
	Span& operator=(Span const& rhs);
	~Span();

	void addNumber(int nb);
	int shortestSpan();
	int longestSpan();

	void printSpan();
};

#endif