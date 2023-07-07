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

# include <climits>
# include <vector>
# include <algorithm>

class Span
{
private:
	std::vector<int> vec;
	const unsigned int n;
public:
	Span();
	Span(unsigned int N);
	Span(Span const& rhs);
	Span& operator=(Span const& rhs);
	~Span();

	void addNumber(int nb);
	template <typename T>
	void addRange(T begin, T end)
	{
		if (end - begin + vec.size() > n)
			throw std::exception();
		for (; begin != end; begin++)
			addNumber(*begin);
	}
	int shortestSpan();
	int longestSpan();
};

#endif