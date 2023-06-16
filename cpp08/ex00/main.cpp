/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:30:25 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/08 20:30:25 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> intvec;
  std::list<int> intlist;
  std::deque<int> intdeque;

  // std::vector<int> test
  intvec.push_back(5);
  intvec.push_back(10);
  std::cout << "Vector test:" << std::endl;
  try {
    std::vector<int>::iterator itr = easyfind(intvec, 10);
    std::cout << "Number found: " << *itr << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << " Number not found" << std::endl;
  }
  try {
    std::vector<int>::iterator itr = easyfind(intvec, 5);
    std::cout << "Number found: " << *itr << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << " Number not found" << std::endl;
  }
  try {
    std::vector<int>::iterator itr = easyfind(intvec, 51);
    std::cout << "Number found: " << *itr << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << " Number not found" << std::endl;
  }
  std::cout << std::endl;

  // std::list<int> test
  intlist.push_back(55);
  intlist.push_back(10);
  std::cout << "List test:" << std::endl;
  try {
    std::list<int>::iterator itr = easyfind(intlist, 10);
    std::cout << "Number found: " << *itr << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << " Number not found" << std::endl;
  }
  try {
    std::list<int>::iterator itr = easyfind(intlist, 5);
    std::cout << "Number found: " << *itr << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << " Number not found" << std::endl;
  }
  intlist.remove(10);
  try {
    std::list<int>::iterator itr = easyfind(intlist, 10);
    std::cout << "Number found: " << *itr << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << " Number not found" << std::endl;
  }
  std::cout << std::endl;

  // std::deque<int> test
  intdeque.push_back(55);
  intdeque.push_back(10);
  std::cout << "Deque test:" << std::endl;
  try {
    std::deque<int>::iterator itr = easyfind(intdeque, 10);
    std::cout << "Number found: " << *itr << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << " Number not found" << std::endl;
  }
  try {
    std::deque<int>::iterator itr = easyfind(intdeque, 5);
    std::cout << "Number found: " << *itr << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << " Number not found" << std::endl;
  }
  intdeque.clear();
  try {
    std::deque<int>::iterator itr = easyfind(intdeque, 10);
    std::cout << "Number found: " << *itr << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << " Number not found" << std::endl;
  }
}