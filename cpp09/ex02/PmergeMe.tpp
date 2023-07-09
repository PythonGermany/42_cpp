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
void PmergeMe::mergeSort(T& data, size_t start, size_t end, C comp, T& sml) {
  if (end - start < 2) return;
  size_t mid = start + (end - start) / 2;
  // Recursively sort two halfes
  mergeSort<T>(data, start, mid, comp, sml);
  mergeSort<T>(data, mid, end, comp, sml);
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
T PmergeMe::binarySearchOld(int& target, T start, T end) {
  if (end - start < 1) return end;
  T mid = start + (end - start) / 2;
#ifdef COUNT
  compCount++;
#endif
  if (*mid < target) return binarySearch(target, mid + 1, end);
  return binarySearch(target, start, mid);
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
      loc = binarySearchOld(small[i], big.begin(), big.begin() + ++insCnt + i);
      big.insert(loc, small[i]);
    }
    int temp = jac;
    jac += 2 * jacPrev;
    jacPrev = temp;
  }
  std::swap(data, big);
}

template <typename T>
T PmergeMe::binarySearch(int& target, T start, T end, size_t range) {
  if (end - start < 1) return end;
  T mid = start + (end - start) / 2;
  if (*mid < target) return binarySearch(target, mid + range, end, range);
  return binarySearch(target, start, mid, range);
}

template <typename C, typename T>
void PmergeMe::mergeInsertSort(T begin, T end, size_t range) {
  const size_t size = end - begin;
  if (size < 2 * range) return;

  for (size_t i = 0; i < size - range; i += 2 * range) {
    if (begin[i] < begin[i + range])
      for (size_t j = i; j < i + range; j++)
        std::swap(begin[j], begin[j + range]);
  }
  mergeInsertSort<C>(begin, begin + size / 2, range + 1);

  C tmp;
  for (size_t i = 0; i < size - range; i += 2 * range)
    for (size_t j = i; j < i + range; j++) tmp.push_back(begin[j]);

  typename C::iterator loc;
  size_t smlSize = size / range / 2;
  size_t jacPrev = 1, jac = 3, insCnt = 0;
  smlSize += (size / range) % 2;
  for (size_t i = 0; i < range; i++)
    tmp.insert(tmp.begin() + i, begin[range + i]);
  while (jacPrev < smlSize) {
    std::cout << "jac: " << jac << " | jacPrev: " << jacPrev << std::endl;
    for (size_t i = std::min(jac - 1, smlSize - 1); i >= jacPrev; i--) {
      loc = binarySearch(begin[(2 * i + 1) * range], tmp.begin(),
                         tmp.begin() + ++insCnt + i * range, range);
      for (size_t j = 0; j < range; j++)
        tmp.insert(loc + j, begin[(2 * i + 1) * range + j]);
    }
    int temp = jac;
    jac += 2 * jacPrev;
    jacPrev = temp;
  }

  std::cout << "Data for " << range << ": ";
  for (size_t i = 0; i < size; i += range) {
    for (size_t j = i; j < i + range; j++) std::cout << begin[j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl;
  std::cout << "Tmp for " << range << ":  ";
  for (size_t i = 0; i < tmp.size(); i += range) {
    for (size_t j = i; j < i + range; j++) std::cout << tmp[j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl << std::endl;
  std::copy(tmp.begin(), tmp.end(), begin);
}

#endif