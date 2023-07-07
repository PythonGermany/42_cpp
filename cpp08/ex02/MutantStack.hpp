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
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack<T> const& rhs);
	MutantStack<T>& operator=(MutantStack<T> const& rhs);
	~MutantStack();

	struct iterator
	{
		typedef std::bidirectional_iterator_tag iterator_category;
    	typedef std::ptrdiff_t difference_type;
    	typedef T value_type;
    	typedef T* pointer;
    	typedef T& reference;
	private:
		int index;
		MutantStack &stack;
	public:
		iterator();
		iterator(int index, MutantStack &stack);
		iterator(iterator const& rhs);
		iterator& operator=(iterator const& rhs);
		~iterator();

		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		bool operator==(iterator const& rhs);
		bool operator!=(iterator const& rhs);
		T& operator*();
		T* operator->();
	};
	MutantStack<T>::iterator begin();
	MutantStack<T>::iterator end();
};

# include "MutantStack.tpp"

#endif