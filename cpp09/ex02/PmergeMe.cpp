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
  // DEV copy second container
  return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::loadSequence(std::vector<std::string>& seq) {
  if (seq.empty()) handleError("Loading: Empty sequence", 1);
  vec.clear();
  // DEV clear second container
  for (size_t i = 0; i < seq.size(); i++) {
    while (seq[i].length() > 0) {
      std::string value = seq[i].substr(0, seq[i].find(' '));
      if (verifyValue(value)) handleError("Loading: Invalid sequence", 1);
      vec.push_back(std::atoi(value.c_str()));
      // DEV add to second container
      seq[i].erase(0, value.size() + 1);
    }
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
  // DEV print second container
}

int PmergeMe::verifyValue(std::string& value) {
  if (value.empty()) return (1);
  if (value.size() > 10) return (1);
  for (size_t i = 0; i < value.length(); i++)
    if (!std::isdigit(value[i])) return (1);
  return (0);
}

void PmergeMe::handleError(std::string msg, int exitCode) {
  std::cout << "Error: " << msg << "!" << std::endl;
  std::exit(exitCode);
}