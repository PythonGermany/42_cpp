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

void PmergeMe::mergeInsertSortOne(std::vector<int>& data) {
  const size_t size = data.size();
  if (size < 2) return;

  // Create ordered pairs
  std::vector<std::pair<int, int> > pairs;
  pairs.reserve(size / 2);
  for (size_t i = 0; i < size - 1; i += 2) {
    if (data[i] < data[i + 1]) std::swap(data[i], data[i + 1]);
    pairs.push_back(std::make_pair(data[i], data[i + 1]));
  }
  const size_t pairsSize = pairs.size();
  // Recursively sort pairs by looking at bigger element
  mergeSort(pairs, 0, pairsSize, comparePairs);

  std::vector<int> res;
  res.reserve(size);
  // Insert smaller element of smallest biggest element into sorted container
  res.push_back(pairs[0].second);
  // Fill container with bigger sorted elements
  for (size_t i = 0; i < pairsSize; i++) res.push_back(pairs[i].first);

  int insert = 0;
  std::vector<int>::iterator insertLoc;
  size_t jacPrev = 1, jac = 1;
  // Insert second smaller element into sorted container using binary search
  if (pairsSize > 1) {
    int curr = pairs[1].second;
    insertLoc = binarySearch(curr, res.begin(), res.begin() + ++insert + 1);
    res.insert(insertLoc, curr);
  }
  // Insert remaining smaller elements into sorted container using binary search
  // in an order derived from Jacobsthal number sequence
  while (jacPrev < pairsSize) {
    for (size_t i = std::min(jac, pairsSize - 1); i > jacPrev; i--) {
      int curr = pairs[i].second;
      insertLoc = binarySearch(curr, res.begin(), res.begin() + ++insert + i);
      res.insert(insertLoc, curr);
    }
    int temp = jac;
    jac += 2 * jacPrev;
    jacPrev = temp;
  }
  // Insert last unmatched element into sorted container if element count is odd
  if (size % 2 == 1)
    res.insert(binarySearch(data.back(), res.begin(), res.end()), data.back());
  std::swap(data, res);
}

void PmergeMe::mergeInsertSortTwo(std::deque<int>& data) {
  const size_t size = data.size();
  if (size < 2) return;

  // Create ordered pairs
  std::deque<std::pair<int, int> > pairs;
  for (size_t i = 0; i < size - 1; i += 2) {
    if (data[i] < data[i + 1]) std::swap(data[i], data[i + 1]);
    pairs.push_back(std::make_pair(data[i], data[i + 1]));
  }
  const size_t pairsSize = pairs.size();
  // Recursively sort pairs by looking at bigger element
  mergeSort(pairs, 0, pairsSize, comparePairs);

  std::deque<int> res;
  // Insert smaller element of smallest biggest element into sorted container
  res.push_back(pairs[0].second);
  // Fill container with bigger sorted elements
  for (size_t i = 0; i < pairsSize; i++) res.push_back(pairs[i].first);

  int insert = 0;
  std::deque<int>::iterator insertLoc;
  size_t jacPrev = 1, jac = 1;
  // Insert second smaller element into sorted container using binary search
  if (pairsSize > 1) {
    int curr = pairs[1].second;
    insertLoc = binarySearch(curr, res.begin(), res.begin() + ++insert + 1);
    res.insert(insertLoc, curr);
  }
  // Insert remaining smaller elements into sorted container using binary search
  // in an order derived from Jacobsthal number sequence
  while (jacPrev < pairsSize) {
    for (size_t i = std::min(jac, pairsSize - 1); i > jacPrev; i--) {
      int curr = pairs[i].second;
      insertLoc = binarySearch(curr, res.begin(), res.begin() + ++insert + i);
      res.insert(insertLoc, curr);
    }
    int temp = jac;
    jac += 2 * jacPrev;
    jacPrev = temp;
  }
  // Insert last unmatched element into sorted container if element count is odd
  if (size % 2 == 1)
    res.insert(binarySearch(data.back(), res.begin(), res.end()), data.back());
  std::swap(data, res);
}

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

std::string PmergeMe::sortContainerOne() {
  long long startTime = getTimeNanos();
  mergeInsertSortOne(vec);
  return removeTrailingZeros(
      (valueToString((getTimeNanos() - startTime) / 1000000.0)));
}

std::string PmergeMe::sortContainerTwo() {
  long long startTime = getTimeNanos();
  mergeInsertSortTwo(que);
  return removeTrailingZeros(
      (valueToString((getTimeNanos() - startTime) / 1000000.0)));
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

void PmergeMe::handleError(std::string msg, int exitCode) {
  std::cout << "Error: " << msg << "!" << std::endl;
  std::exit(exitCode);
}

bool PmergeMe::comparePairs(std::pair<int, int>& a, std::pair<int, int>& b) {
  return a.first < b.first;
}

long long PmergeMe::getTimeNanos() const {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return static_cast<long long>(ts.tv_sec) * 1000000000LL +
         static_cast<long long>(ts.tv_nsec);
}

std::string PmergeMe::valueToString(double val) const {
  std::stringstream ss;
  ss << std::setprecision(std::numeric_limits<double>::digits10 + 1);
  ss << std::fixed << val << std::scientific;
  return ss.str();
}

std::string PmergeMe::removeTrailingZeros(std::string str) const {
  if (str.empty()) return str;
  while (str[str.length() - 1] == '0') {
    if (str.length() < 2 || str[str.length() - 2] == '.') break;
    str.erase(str.length() - 1, 1);
  }
  return str;
}

int PmergeMe::verifyValue(std::string& value) const {
  if (value.empty()) return (1);
  if (value.size() > 10) return (1);
  for (size_t i = 0; i < value.length(); i++) {
    if (i == 0 && (value[i] == '-' || value[i] == '+') && value.length() > 1)
      continue;
    if (!std::isdigit(value[i])) return (1);
  }
  return (0);
}