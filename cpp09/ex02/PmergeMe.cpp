/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:56:22 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/30 16:56:22 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<std::string> seq) { loadSequence(seq); }

PmergeMe::PmergeMe(PmergeMe const& rhs) { *this = rhs; }

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {
  if (this == &rhs) return (*this);
  vec = rhs.vec;
  lst = rhs.lst;
  return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::loadSequence(std::vector<std::string>& seq) {
  if (seq.empty()) handleError("Loading: Empty sequence", 1);
  vec.clear();
  lst.clear();
  for (size_t i = 0; i < seq.size(); i++) {
    if (seq[i].empty()) handleError("Loading: Empty argument", 1);
    if (verifyValue(seq[i])) handleError("Loading: Invalid sequence", 1);
    vec.push_back(std::atoi(seq[i].c_str()));
    lst.push_back(std::atoi(seq[i].c_str()));
  }
}

void PmergeMe::sortContainerOne() {
  // DEV sort first container
}

void PmergeMe::printContainerOne() const {
  for (size_t i = 0; i < vec.size(); i++) std::cout << vec[i] << " ";
  std::cout << std::endl;
}

void PmergeMe::sortContainerTwo() {
  // DEV sort second container
}

void PmergeMe::printContainerTwo() const {
  std::list<int>::const_iterator itr = lst.begin();
  while (itr != lst.end()) std::cout << *itr++ << " ";
  std::cout << std::endl;
}

int PmergeMe::verifyValue(std::string& value) {
  if (value.empty()) return (1);
  if (value.size() > 10) return (1);
  for (size_t i = 0; i < value.length(); i++) {
    if (i == 0 && (value[i] == '-' || value[i] == '+') && value.length() > 1)
      continue;
    if (!std::isdigit(value[i])) return (1);
  }
  return (0);
}

void PmergeMe::handleError(std::string msg, int exitCode) {
  std::cout << "Error: " << msg << "!" << std::endl;
  std::exit(exitCode);
}