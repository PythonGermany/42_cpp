/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:53:15 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/12 17:53:15 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <list>

#include "MutantStack.hpp"

int main() {
  MutantStack<int> mst;
  std::cout << "Size: " << mst.size() << std::endl;
  for (int i = 0; i < 50; i++) mst.push(i + 1);
  std::cout << "Size: " << mst.size() << std::endl;
  MutantStack<int> mstClone = mst;
  std::cout << "Clone Size: " << mstClone.size() << std::endl;
  MutantStack<int>::iterator itr = mst.begin();
  while (itr != mst.end()) std::cout << *itr++ << " ";
  std::cout << std::endl;
  MutantStack<int>::iterator itTemp = std::find(mst.begin(), mst.end(), 24);
  if (itTemp != mst.end())
    std::cout << "Number " << *itTemp << " found in mst" << std::endl;
  else
    std::cout << "Number 24 NOT found in mst" << std::endl;
  itTemp = std::find(mst.begin(), mst.end(), 50);
  if (itTemp != mst.end())
    std::cout << "Number " << *itTemp << " found in mst" << std::endl;
  else
    std::cout << "Number 50 NOT found in mst" << std::endl;
  itTemp = std::find(mst.begin(), mst.end(), 51);
  if (itTemp != mst.end())
    std::cout << "Number " << *itTemp << " found in mst" << std::endl;
  else
    std::cout << "Number 51 NOT found in mst" << std::endl;
  std::cout << std::endl;

  std::cout << "Mutant stack: " << std::endl;
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << " ";
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << std::endl;
  std::stack<int> s(mstack);
  while (s.size() > 0) {
    std::cout << s.top() << " ";
    s.pop();
  }
  std::cout << std::endl << std::endl;

  std::cout << "List: " << std::endl;
  std::list<int> lst;
  lst.push_back(5);
  lst.push_back(17);
  std::cout << lst.back() << " ";
  lst.pop_back();
  std::cout << lst.size() << std::endl;
  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  lst.push_back(0);
  std::list<int>::iterator itlst = lst.begin();
  std::list<int>::iterator itelst = lst.end();
  ++itlst;
  --itlst;
  while (itlst != itelst) {
    std::cout << *itlst << " ";
    ++itlst;
  }
  std::cout << std::endl;
  while (lst.size() > 0) {
    std::cout << lst.back() << " ";
    lst.pop_back();
  }
  std::cout << std::endl << std::endl;

  std::cout << "Stack: " << std::endl;
  std::stack<int> st;
  st.push(5);
  st.push(17);
  std::cout << st.top() << " ";
  st.pop();
  std::cout << st.size() << std::endl;
  st.push(3);
  st.push(5);
  st.push(737);
  st.push(0);
  std::stack<int> s2(st);
  while (s2.size() > 0) {
    std::cout << s2.top() << " ";
    s2.pop();
  }
  std::cout << std::endl;
  return (0);
}