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
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

class PmergeMe {
 public:
#ifdef COUNT
  int compCount;
#endif

  PmergeMe();
  PmergeMe(PmergeMe const& rhs);
  PmergeMe& operator=(PmergeMe const& rhs);
  ~PmergeMe();

  template <typename T, typename C, typename S>
  void loadSequence(S& seq, T& a, C& b);
  template <typename T>
  void printContainer(T& cont) const;
  template <typename T>
  std::string sortContainer(T& cont);
  template <typename T>
  T binarySearch(int& target, T start, T end, size_t range);
  template <typename C, typename T>
  void mergeInsertSort(T begin, T end, size_t range);

  static void handleError(std::string msg, int exitCode);

 private:
  long long getTimeNanos() const;
  std::string valueToString(double val) const;
  std::string removeTrailingZeros(std::string str) const;
  int verifyValue(std::string& value) const;
};

#include "PmergeMe.tpp"

#endif