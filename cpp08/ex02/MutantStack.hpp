/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:40:14 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/12 17:40:14 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack<T> const& rhs);
	MutantStack<T>& operator=(MutantStack<T> const& rhs);
	~MutantStack();

	class iterator
	{
		private:
			int index;
		public:
			iterator(int index);
			iterator(iterator const& rhs);
			iterator& operator=(iterator const& rhs);
			~iterator();

			iterator& operator++();
			iterator operator++(int);
			iterator& operator--();
			iterator operator--(int);
			T& operator*();
	};
	MutantStack<T>::iterator begin();
	MutantStack<T>::iterator end();
};

# include "MutantStack.tpp"

#endif