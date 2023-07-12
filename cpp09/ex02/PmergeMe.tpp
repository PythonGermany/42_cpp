/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:40:52 by rburgsta          #+#    #+#             */
/*   Updated: 2023/07/11 15:02:15 by rburgsta         ###   ########.fr       */
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
void debugPrint(std::string color, std::string msg, T begin, T end,
                size_t chunk, size_t stride = 1, bool newline = false) {
#ifdef DEBUG
  std::cout << color << chunk << ": " << msg << DEFAULT;
  for (T itr = begin; itr < end; itr += chunk * stride) {
    for (size_t i = 0; i < chunk; i++) std::cout << *(itr + i) << " ";
    std::cout << "| ";
  }
  std::cout << std::endl;
  if (newline) std::cout << std::endl;
#endif
#ifndef DEBUG
  (void)color;
  (void)msg;
  (void)begin;
  (void)end;
  (void)chunk;
  (void)stride;
  (void)newline;
#endif
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
  debugPrint(RED, "In:      ", begin, end, chunk);

  // Swap pairs if needed
  for (size_t i = 0; i < size - 1; i += 2) {
    if (begin[i * chunk] < begin[(i + 1) * chunk])
      for (size_t j = 0; j < chunk; j++)
        std::swap(begin[i * chunk + j], begin[(i + 1) * chunk + j]);
#ifdef COUNT
    compCount++;
#endif
  }
  debugPrint(MAGENTA, "Swapped: ", begin, end, chunk, 1, true);

  T stop = end - size % 2 * chunk;
  mergeInsertSort<C>(begin, stop, chunk * 2);

  C tmp;
  // Insert big elements
  for (size_t i = 0; i < size - 1; i += 2)
    insert_chunk(tmp, tmp.end(), begin + i * chunk, chunk);

  debugPrint(RED, "Data:  ", begin, end, chunk);
  debugPrint(YELLOW, "Main:  ", tmp.begin(), tmp.end(), chunk);
  debugPrint(YELLOW, "Small: ", begin + 1 * chunk, end, chunk, 2);

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
      std::cout << BLUE << chunk << ": Insert: " << DEFAULT << "index: " << i
                << " value: " << *curr << std::endl;
#endif
      debugPrint(GREEN, "  Prev:  ", tmp.begin(), tmp.end(), chunk, chunk);
      insert_chunk(tmp, loc, curr, chunk);
      debugPrint(GREEN, "  After: ", tmp.begin(), tmp.end(), chunk, chunk);
    }
    int temp = jac;
    jac += 2 * jacPrev;
    jacPrev = temp;
  }

  debugPrint("\033[36m", "Out:   ", tmp.begin(), tmp.end(), chunk, 1, true);

  // Copy sorted data to original array
  std::copy(tmp.begin(), tmp.end(), begin);
}

#endif