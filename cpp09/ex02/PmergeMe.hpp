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

class PmergeMe {
 private:
  std::vector<int> vec;
  std::deque<int> que;

 public:
  PmergeMe();
  PmergeMe(std::vector<std::string> seq);
  PmergeMe(PmergeMe const& rhs);
  PmergeMe& operator=(PmergeMe const& rhs);
  ~PmergeMe();

  void loadSequence(std::vector<std::string>& seq);
  long long getTimeNanos();
  std::string valueToString(double val);
  std::string removeTrailingZeros(std::string str);
  template <typename T>
  void mergeSort(T start, T end) {
    if (end - start < 2) return;
    T mid = start + (end - start) / 2;
    mergeSort(start, mid);
    mergeSort(mid, end);
    std::inplace_merge(start, mid, end);
  }
  std::string sortContainerOne();
  std::string sortContainerTwo();
  void printContainerOne() const;
  void printContainerTwo() const;
  static void handleError(std::string msg, int exitCode);

 private:
  int verifyValue(std::string& value);
};

#endif