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
  que = rhs.que;
  return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::loadSequence(std::vector<std::string>& seq) {
  if (seq.empty()) handleError("Loading: Empty sequence", 1);
  vec.clear();
  que.clear();
  for (size_t i = 0; i < seq.size(); i++) {
    if (seq[i].empty()) handleError("Loading: Empty argument", 1);
    if (verifyValue(seq[i])) handleError("Loading: Invalid sequence", 1);
    vec.push_back(std::atoi(seq[i].c_str()));
    que.push_back(std::atoi(seq[i].c_str()));
  }
}

long long PmergeMe::getTimeNanos() {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return static_cast<long long>(ts.tv_sec) * 1000000000LL +
         static_cast<long long>(ts.tv_nsec);
}

std::string PmergeMe::valueToString(double val) {
  std::stringstream ss;
  ss << std::setprecision(std::numeric_limits<double>::digits10 + 1);
  ss << std::fixed << val << std::scientific;
  return ss.str();
}

std::string PmergeMe::removeTrailingZeros(std::string str) {
  if (str.empty()) return str;
  while (str[str.length() - 1] == '0') {
    if (str.length() < 2 || str[str.length() - 2] == '.') break;
    str.erase(str.length() - 1, 1);
  }
  return str;
}

template <typename T>
T binarySearch(int& target, T start, T end) {
  if (end - start < 1) return end;
  T mid = start + (end - start) / 2;
  if (*mid == target) return mid;
  if (*mid < target) return binarySearch(target, mid + 1, end);
  return binarySearch(target, start, mid);
}

template <typename T>
void mergeInsertSort(T& data) {
  const int size = data.size();
  if (size < 2) return;
  T sorted;
  for (int i = 1; i < size; i += 2) {
    if (data[i - 1] < data[i]) std::swap(data[i - 1], data[i]);
    sorted.push_back(data[i]);
  }
  mergeInsertSort(sorted);
  for (int i = 0; i < size; i += 2)
    sorted.insert(binarySearch(data[i], sorted.begin(), sorted.end()), data[i]);
  data = sorted;
}

std::string PmergeMe::sortContainerOne() {
  long long startTime = getTimeNanos();
  mergeInsertSort(vec);
  return removeTrailingZeros(
      (valueToString((getTimeNanos() - startTime) / 1000.0)));
}

std::string PmergeMe::sortContainerTwo() {
  long long startTime = getTimeNanos();
  return removeTrailingZeros(
      (valueToString((getTimeNanos() - startTime) / 1000.0)));
}

void PmergeMe::printContainerOne() const {
  for (size_t i = 0; i < vec.size(); i++) std::cout << vec[i] << " ";
  std::cout << std::endl;
}

void PmergeMe::printContainerTwo() const {
  std::deque<int>::const_iterator itr = que.begin();
  while (itr != que.end()) std::cout << *itr++ << " ";
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