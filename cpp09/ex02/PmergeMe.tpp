/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:40:52 by rburgsta          #+#    #+#             */
/*   Updated: 2023/07/10 17:37:03 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

template <typename T, typename C>
void PmergeMe::mergeSort(T& data, size_t start, size_t end, C comp, T& sml) {
  if (end - start < 2) return;
  size_t mid = start + (end - start) / 2;
  mergeSort<T>(data, start, mid, comp, sml);
  mergeSort<T>(data, mid, end, comp, sml);
  T tmp(end - start);
  T smlTmp(end - start);
  size_t l = start, r = mid;
  for (size_t i = 0; i < tmp.size(); i++) {
    if (l == mid) {
      smlTmp[i] = sml[r];
      tmp[i] = data[r++];
    } else if (r == end) {
      smlTmp[i] = sml[l];
      tmp[i] = data[l++];
    } else {
#ifdef COUNT
      compCount++;
#endif
      smlTmp[i] = comp(data[l], data[r]) ? sml[l] : sml[r];
      tmp[i] = comp(data[l], data[r]) ? data[l++] : data[r++];
    }
  }
  std::copy(tmp.begin(), tmp.end(), data.begin() + start);
  std::copy(smlTmp.begin(), smlTmp.end(), sml.begin() + start);
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

template <typename T>
void PmergeMe::mergeInsertSortWrong(T& data) {
  const size_t size = data.size();
  if (size < 2) return;

  T big(size / 2), small(size / 2 + size % 2);
  size_t smlSize = small.size();
  for (size_t i = 0; i < size - 1; i += 2) {
    if (data[i] > data[i + 1]) std::swap(data[i], data[i + 1]);
    big[i / 2] = data[i + 1];
    small[i / 2] = data[i];
#ifdef COUNT
    compCount++;
#endif
  }
  if (size % 2) small.back() = data.back();
  mergeSort(big, 0, big.size(), compareInts, small);

  typename T::iterator loc;
  size_t jacPrev = 1, jac = 3, insCnt = 0;
  big.insert(big.begin(), small[0]);
  while (jacPrev < smlSize) {
    for (size_t i = std::min(jac - 1, smlSize - 1); i >= jacPrev; i--) {
      loc = binarySearch(small[i], big.begin(), big.begin() + ++insCnt + i, 1);
      big.insert(loc, small[i]);
    }
    int temp = jac;
    jac += 2 * jacPrev;
    jacPrev = temp;
  }
  std::swap(data, big);
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
    if (begin[i] < begin[(i + 1) * chunk])
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

  C tmp, small;
  // Init big elements
  for (size_t i = 0; i < size - 1; i += 2)
    insert_chunk(tmp, tmp.end(), begin + i * chunk, chunk);
  // Init small elements
  for (size_t i = 1; i < size; i += 2)
    insert_chunk(small, small.end(), begin + i * chunk, chunk);
  // Init last element if size is odd
  if (size % 2) insert_chunk(small, small.end(), end - chunk, chunk);

#ifdef DEBUG
  std::cout << "Small: ";
  for (size_t i = 0; i < small.size() / chunk; i++) {
    for (size_t j = 0; j < chunk; j++) std::cout << small[i * chunk + j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl;
  std::cout << "Main:  ";
  for (size_t i = 0; i < tmp.size() / chunk; i++) {
    for (size_t j = 0; j < chunk; j++) std::cout << tmp[i * chunk + j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl;
#endif

  typename C::iterator loc;
  size_t smlSize = (size + 1) / 2;
  size_t jacPrev = 1, jac = 3, insCnt = 1;
  for (size_t j = 0; j < chunk; j++) tmp.insert(tmp.begin() + j, small[j]);
  while (jacPrev < smlSize) {
    for (size_t i = std::min(jac - 1, smlSize - 1); i >= jacPrev; i--) {
      typename C::iterator curr = small.begin() + i * chunk;
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

#ifdef DEBUG
  std::cout << "\033[33m Out for " << chunk << ":  \033[39m";
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