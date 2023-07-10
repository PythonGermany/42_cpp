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
T PmergeMe::binarySearch(int& target, T start, T end, size_t block) {
  if (end - start < 1) return end;
  T mid = start + (end - start) / 2;
  if (*mid < target) return binarySearch(target, mid + block, end, block);
  return binarySearch(target, start, mid, block);
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

// Doesn't work
// template <typename C, typename T>
// void insert_block(C& data, T dst, T src, size_t block) {
//   for (size_t i = 0; i < block; i++) data.insert(dst++, src[i]);
// }

template <typename C, typename T>
void PmergeMe::mergeInsertSort(T begin, T end, size_t block) {
  const size_t size = end - begin;
  if (size < 2 * block) return;

  for (size_t i = 0; i < size - block; i += 2 * block) {
    if (begin[i] < begin[i + block])
      for (size_t j = i; j < i + block; j++)
        std::swap(begin[j], begin[j + block]);
  }
  T stop = end - block * (size / block % 2);
  mergeInsertSort<C>(begin, stop, block * 2);

  C tmp, small;
  for (size_t i = 0; i < size - block; i += 2 * block)
    for (size_t j = i; j < i + block; j++) tmp.insert(tmp.end(), begin[j]);
  for (size_t i = block; i < size; i += 2 * block)
    for (size_t j = i; j < i + block; j++) small.insert(small.end(), begin[j]);
  if (size / block % 2)
    for (size_t j = size - block; j < size; j++)
      small.insert(small.end(), begin[j]);
  std::cout << "Small for " << block << ": ";
  for (size_t i = 0; i < small.size(); i += block) {
    for (size_t j = i; j < i + block; j++) std::cout << small[j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl;

  typename C::iterator loc;
  size_t smlSize = size / block / 2 + size / block % 2;
  size_t jacPrev = 1, jac = 3, insCnt = 0;
  for (size_t i = 0; i < block; i++) tmp.insert(tmp.begin() + i, small[i]);
  while (jacPrev < smlSize) {
    // std::cout << "jac: " << jac << " | jacPrev: " << jacPrev << std::endl;
    for (size_t i = std::min(jac - 1, smlSize - 1); i >= jacPrev; i--) {
      loc = binarySearch(small[i * block], tmp.begin(),
                         tmp.begin() + (++insCnt + i) * block, block);
      // std::cout << "index: " << i << std::endl;
      for (size_t j = 0; j < block; j++)
        tmp.insert(loc + j, small[i * block + j]);
    }
    int temp = jac;
    jac += 2 * jacPrev;
    jacPrev = temp;
  }

  std::cout << "Data for " << block << ": ";
  for (size_t i = 0; i < size; i += block) {
    for (size_t j = i; j < i + block; j++) std::cout << begin[j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl;
  std::cout << "Tmp for " << block << ":  ";
  for (size_t i = 0; i < tmp.size(); i += block) {
    for (size_t j = i; j < i + block; j++) std::cout << tmp[j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl << std::endl;
  std::copy(tmp.begin(), tmp.end(), begin);
}

#endif