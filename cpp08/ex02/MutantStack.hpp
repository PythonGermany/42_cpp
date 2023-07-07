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
#define MUTANTSTACK_HPP

#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack();
  MutantStack(MutantStack<T> const& rhs);
  MutantStack<T>& operator=(MutantStack<T> const& rhs);
  ~MutantStack();

  class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
   private:
    int index;
    MutantStack& stack;

   public:
    iterator();
    iterator(int index, MutantStack<T>& stack);
    iterator(iterator const& rhs);
    iterator& operator=(iterator const& rhs);
    ~iterator();

    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    T& operator*();
    T* operator->();
    bool operator==(iterator const& rhs) const;
    bool operator!=(iterator const& rhs) const;
  };
  iterator begin();
  iterator end();
};

#include "MutantStack.tpp"

#endif