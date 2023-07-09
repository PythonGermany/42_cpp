/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:40:52 by rburgsta          #+#    #+#             */
/*   Updated: 2023/07/08 17:47:25 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

template <typename T, typename C>
void PmergeMe::mergeSort(T& data, size_t start, size_t end, C comp) {
  if (end - start < 2) return;
  size_t mid = start + (end - start) / 2;
  // Recursively sort two halfes
  mergeSort<T>(data, start, mid, comp);
  mergeSort<T>(data, mid, end, comp);
  // Merge two sorted halfes into one sorted part
  T tmp(end - start);
  size_t l = start, r = mid;
  for (size_t i = 0; i < tmp.size(); i++) {
    if (l == mid)
      tmp[i] = data[r++];
    else if (r == end)
      tmp[i] = data[l++];
    else {
#ifdef COUNT
      compCount++;
#endif
      tmp[i] = comp(data[l], data[r]) ? data[l++] : data[r++];
    }
  }
  std::copy(tmp.begin(), tmp.end(), data.begin() + start);
}

template <typename T, typename C>
void PmergeMe::mergeSortTest(T& data, size_t start, size_t end, C comp,
                             T& sml) {
  if (end - start < 2) return;
  size_t mid = start + (end - start) / 2;
  // Recursively sort two halfes
  mergeSortTest<T>(data, start, mid, comp, sml);
  mergeSortTest<T>(data, mid, end, comp, sml);
  // Merge two sorted halfes into one sorted part
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
T PmergeMe::binarySearch(int& target, T start, T end) {
  if (end - start < 1) return end;
  T mid = start + (end - start) / 2;
#ifdef COUNT
  compCount++;
#endif
  if (*mid < target) return binarySearch(target, mid + 1, end);
  return binarySearch(target, start, mid);
}

template <typename T>
void PmergeMe::mergeInsertSortTest(T& data, T* sml) {
  (void)sml;
  if (size < 2) return;

  const size_t size = data.size();
  T big(size / 2);
  T small(size / 2 + size % 2);
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
  mergeSortTest(big, 0, big.size(), compareInts, small);

  int insert = 0;
  typename T::iterator insertLoc;
  size_t jacPrev = 1, jac = 3;
  big.insert(big.begin(), small[0]);
  while (jacPrev < smlSize) {
    for (size_t i = std::min(jac - 1, smlSize - 1); i >= jacPrev; i--) {
      int curr = small[i];
      insertLoc = binarySearch(curr, big.begin(), big.begin() + ++insert + i);
      big.insert(insertLoc, curr);
    }
    int temp = jac;
    jac += 2 * jacPrev;
    jacPrev = temp;
  }
  std::swap(data, big);
}

#endif