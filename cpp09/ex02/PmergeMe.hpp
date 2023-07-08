/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:56:32 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/30 16:56:32 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>

#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

#define COUNT

class PmergeMe {
#ifdef COUNT
 public:
  int compCount;
#endif
 private:
  std::vector<int> vec;
  std::deque<int> que;

 public:
  PmergeMe();
  PmergeMe(std::vector<std::string> seq);
  PmergeMe(PmergeMe const& rhs);
  PmergeMe& operator=(PmergeMe const& rhs);
  ~PmergeMe();

  template <typename T, typename C>
  void mergeSort(T& data, size_t start, size_t end, C comp);
  template <typename T>
  T binarySearch(int& target, T start, T end);

  void mergeInsertSortOne(std::vector<int>& data);
  void mergeInsertSortTwo(std::deque<int>& data);
  void loadSequence(std::vector<std::string>& seq);
  std::string sortContainerOne();
  std::string sortContainerTwo();
  void printContainerOne() const;
  void printContainerTwo() const;
  static void handleError(std::string msg, int exitCode);

 private:
  static bool comparePairs(std::pair<int, int>& a, std::pair<int, int>& b);
  long long getTimeNanos() const;
  std::string valueToString(double val) const;
  std::string removeTrailingZeros(std::string str) const;
  int verifyValue(std::string& value) const;
};

#include "PmergeMe.tpp"

#endif