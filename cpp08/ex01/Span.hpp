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
# include <list>
# include <algorithm>

class Span
{
private:
	std::list<int> lst;
	const size_t n;
public:
	Span();
	Span(unsigned int N);
	Span(Span const& rhs);
	Span& operator=(Span const& rhs);
	~Span();

	void addNumber(int nb);
	int shortestSpan();
	int longestSpan();
};

#endif