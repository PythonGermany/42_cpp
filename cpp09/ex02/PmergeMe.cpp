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

PmergeMe::PmergeMe() {
#ifdef COUNT
  compCount = 0;
#endif
}

PmergeMe::PmergeMe(std::vector<std::string> seq) {
#ifdef COUNT
  compCount = 0;
#endif
  loadSequence(seq);
}

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
#ifdef COUNT
    compCount++;
#endif
  }

  // Recursively sort pairs by looking at bigger element
  size_t pairsSize = pairs.size();
  mergeSort(pairs, 0, pairsSize, comparePairs);

  // Fill container with bigger sorted elements
  std::vector<int> res;
  res.reserve(size);
  for (size_t i = 0; i < pairsSize; i++) res.push_back(pairs[i].first);

  // Add unpaired element if existent
  if (size % 2) pairs.push_back(std::make_pair(-1, data.back()));
  pairsSize += size % 2;

  // Insert smaller element of smallest pair into sorted container
  res.insert(res.begin(), pairs[0].second);

  int insert = 0;
  std::vector<int>::iterator insertLoc;
  size_t jacPrev = 1, jac = 3;
  // Insert remaining smaller elements into sorted container using binary search
  // in an order derived from Jacobsthal number sequence
  while (jacPrev < pairsSize) {
    for (size_t i = std::min(jac - 1, pairsSize - 1); i >= jacPrev; i--) {
      int curr = pairs[i].second;
      insertLoc = binarySearch(curr, res.begin(), res.begin() + ++insert + i);
      res.insert(insertLoc, curr);
    }
    int temp = jac;
    jac += 2 * jacPrev;
    jacPrev = temp;
  }
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
#ifdef COUNT
    compCount++;
#endif
  }

  // Recursively sort pairs by looking at bigger element
  size_t pairsSize = pairs.size();
  mergeSort(pairs, 0, pairsSize, comparePairs);

  // Fill container with bigger sorted elements
  std::deque<int> res;
  for (size_t i = 0; i < pairsSize; i++) res.push_back(pairs[i].first);

  // Add unpaired element if existent
  if (size % 2) pairs.push_back(std::make_pair(-1, data.back()));
  pairsSize += size % 2;

  // Insert smaller element of smallest pair into sorted container
  res.insert(res.begin(), pairs[0].second);

  int insert = 0;
  std::deque<int>::iterator insertLoc;
  size_t jacPrev = 1, jac = 3;
  // Insert remaining smaller elements into sorted container using binary
  // search in an order derived from Jacobsthal number sequence
  while (jacPrev < pairsSize) {
    for (size_t i = std::min(jac - 1, pairsSize - 1); i > jacPrev - 1; i--) {
      int curr = pairs[i].second;
      insertLoc = binarySearch(curr, res.begin(), res.begin() + ++insert + i);
      res.insert(insertLoc, curr);
    }
    int temp = jac;
    jac += 2 * jacPrev;
    jacPrev = temp;
  }
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
  mergeInsertSortTest(vec, (std::vector<int>*)NULL);
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

bool PmergeMe::compareInts(int& a, int& b) { return a < b; }

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
  for (size_t i = 0; i < value.length(); i++)
    if (!std::isdigit(value[i])) return (1);
  return (0);
}