/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:40:52 by rburgsta          #+#    #+#             */
/*   Updated: 2023/07/10 18:16:17 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

template <typename T, typename C, typename S>
void PmergeMe::loadSequence(S& seq, T& a, C& b) {
  if (seq.empty()) handleError("Loading: Empty sequence", 1);
  a.clear();
  b.clear();
  for (size_t i = 0; i < seq.size(); i++) {
    if (seq[i].empty()) handleError("Loading: Empty argument", 1);
    if (verifyValue(seq[i])) handleError("Loading: Invalid sequence", 1);
    a.push_back(std::atoi(seq[i].c_str()));
    b.push_back(std::atoi(seq[i].c_str()));
  }
}

template <typename T>
void PmergeMe::printContainer(T& cont) const {
  typename T::const_iterator itr = cont.begin();
  while (itr != cont.end()) std::cout << *itr++ << " ";
  std::cout << std::endl;
}

template <typename T>
std::string PmergeMe::sortContainer(T& cont) {
  long long startTime = getTimeNanos();
  mergeInsertSort<T>(cont.begin(), cont.end(), 1);
  return removeTrailingZeros(
      (valueToString((getTimeNanos() - startTime) / 1000000.0)));
}

template <typename T>
T PmergeMe::binarySearch(int& target, T start, T end, size_t chunk) {
  size_t size = (end - start) / chunk;
  if (size < 1) return end;
  T mid = start + (size / 2) * chunk;
#ifdef COUNT
  compCount++;
#endif
  if (*mid < target) return binarySearch(target, mid + chunk, end, chunk);
  return binarySearch(target, start, mid, chunk);
}

template <typename C, typename T>
void insert_chunk(C& data, T dst, T src, size_t chunk) {
  for (size_t j = 0; j < chunk; j++) dst = data.insert(dst, src[chunk - j - 1]);
}

template <typename C, typename T>
void PmergeMe::mergeInsertSort(T begin, T end, size_t chunk) {
  const size_t size = (end - begin) / chunk;
  if (size < 2) return;

#ifdef DEBUG
  std::cout << "\033[31m" << chunk << ": In:      \033[39m";
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < chunk; j++) std::cout << begin[i * chunk + j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl;
#endif

  // Swap pairs if needed
  for (size_t i = 0; i < size - 1; i += 2) {
    if (begin[i * chunk] < begin[(i + 1) * chunk])
      for (size_t j = 0; j < chunk; j++)
        std::swap(begin[i * chunk + j], begin[(i + 1) * chunk + j]);
#ifdef COUNT
    compCount++;
#endif
  }

#ifdef DEBUG
  std::cout << "\033[35m" << chunk << ": Swapped: \033[39m";
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < chunk; j++) std::cout << begin[i * chunk + j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl << std::endl;
#endif

  T stop = end - size % 2 * chunk;
  mergeInsertSort<C>(begin, stop, chunk * 2);

  C tmp;
  // Insert big elements
  for (size_t i = 0; i < size - 1; i += 2)
    insert_chunk(tmp, tmp.end(), begin + i * chunk, chunk);

#ifdef DEBUG
  std::cout << "Main:  ";
  for (size_t i = 0; i < tmp.size() / chunk; i++) {
    for (size_t j = 0; j < chunk; j++) std::cout << tmp[i * chunk + j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl;
#endif

  // Insert smaller elements into main chain based on the Jacobsthal Numbers
  typename C::iterator loc;
  typename C::iterator curr;
  size_t smlSize = (size + 1) / 2;
  size_t jacPrev = 1, jac = 3, insCnt = 1;
  insert_chunk(tmp, tmp.begin(), begin + chunk, chunk);
  while (jacPrev < smlSize) {
    size_t i = std::min(jac - 1, smlSize - 1);
    if (size % 2 && i == smlSize - 1) {
      loc = binarySearch(*(end - chunk), tmp.begin(),
                         tmp.begin() + (insCnt++ + i--) * chunk, chunk);
      insert_chunk(tmp, loc, end - chunk, chunk);
    }
    for (; i >= jacPrev; i--) {
      curr = begin + (i * 2 + 1) * chunk;
      loc = binarySearch(*curr, tmp.begin(),
                         tmp.begin() + (insCnt++ + i) * chunk, chunk);
#ifdef DEBUG
      std::cout << "\033[34m Insert: \033[39m"
                << "index: " << i << " value: " << *curr << std::endl;
      std::cout << "\033[32m     Prev:  \033[39m";
      for (size_t i = 0; i < tmp.size() / chunk; i++) {
        for (size_t j = 0; j < chunk; j++)
          std::cout << tmp[i * chunk + j] << " ";
        std::cout << "| ";
      }
      std::cout << std::endl;
#endif
      insert_chunk(tmp, loc, curr, chunk);
#ifdef DEBUG
      std::cout << "\033[32m     After: \033[39m";
      for (size_t i = 0; i < tmp.size() / chunk; i++) {
        for (size_t j = 0; j < chunk; j++)
          std::cout << tmp[i * chunk + j] << " ";
        std::cout << "| ";
      }
      std::cout << std::endl;
#endif
    }
    int temp = jac;
    jac += 2 * jacPrev;
    jacPrev = temp;
  }

  // Init last element if size is odd

#ifdef DEBUG
  std::cout << "\033[33mOut for " << chunk << ":  \033[39m";
  for (size_t i = 0; i < tmp.size() / chunk; i++) {
    for (size_t j = 0; j < chunk; j++) std::cout << tmp[i * chunk + j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl << std::endl;
#endif

  // Copy sorted data to original array
  std::copy(tmp.begin(), tmp.end(), begin);
}

#endif