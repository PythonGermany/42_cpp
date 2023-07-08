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

#endif