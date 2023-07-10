/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:40:52 by rburgsta          #+#    #+#             */
/*   Updated: 2023/07/10 16:23:20 by rburgsta         ###   ########.fr       */
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
  size_t size = (end - start) / block;
  if (size < 1) return end;
  T mid = start + (size / 2) * block;
#ifdef COUNT
  compCount++;
#endif
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

template <typename C, typename T>
void insert_block(C& data, T dst, T src, size_t block) {
  for (size_t j = 0; j < block; j++) dst = data.insert(dst, src[block - j - 1]);
}

template <typename C, typename T>
void PmergeMe::mergeInsertSort(T begin, T end, size_t block) {
  const size_t size = (end - begin) / block;
  if (size < 2) return;

  // Swap pairs if needed
  for (size_t i = 0; i < size - 1; i += 2) {
    if (begin[i] < begin[(i + 1) * block])
      for (size_t j = 0; j < block; j++)
        std::swap(begin[i * block + j], begin[(i + 1) * block + j]);
#ifdef COUNT
    compCount++;
#endif
  }
  T stop = end - size % 2 * block;
  mergeInsertSort<C>(begin, stop, block * 2);

  C tmp, small;
  // Init big elements
  for (size_t i = 0; i < size - 1; i += 2)
    insert_block(tmp, tmp.end(), begin + i * block, block);
  // Init small elements
  for (size_t i = 1; i < size; i += 2)
    insert_block(small, small.end(), begin + i * block, block);
  // Init last element if size is odd
  if (size % 2) insert_block(small, small.end(), end - block, block);

#ifdef DEBUG
  std::cout << "\033[31m"
            << "Data for " << block << ": \033[39m";
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < block; j++) std::cout << begin[i * block + j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl;
  std::cout << "Small for " << block << ": ";
  for (size_t i = 0; i < small.size() / block; i++) {
    for (size_t j = 0; j < block; j++) std::cout << small[i * block + j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl;
  std::cout << "Main for " << block << ": ";
  for (size_t i = 0; i < tmp.size() / block; i++) {
    for (size_t j = 0; j < block; j++) std::cout << tmp[i * block + j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl;
#endif

  typename C::iterator loc;
  size_t smlSize = (size + 1) / 2;
  size_t jacPrev = 1, jac = 3, insCnt = 1;
  for (size_t j = 0; j < block; j++) tmp.insert(tmp.begin() + j, small[j]);
  while (jacPrev < smlSize) {
    for (size_t i = std::min(jac - 1, smlSize - 1); i >= jacPrev; i--) {
      typename C::iterator curr = small.begin() + i * block;
      loc = binarySearch(*curr, tmp.begin(),
                         tmp.begin() + (insCnt++ + i) * block, block);
#ifdef DEBUG
      std::cout << "\033[34m Insert: \033[39m"
                << "index: " << i << " value: " << *curr << std::endl;
      std::cout << "\033[32m     Prev:  \033[39m";
      for (size_t i = 0; i < tmp.size() / block; i++) {
        for (size_t j = 0; j < block; j++)
          std::cout << tmp[i * block + j] << " ";
        std::cout << "| ";
      }
      std::cout << std::endl;
#endif
      insert_block(tmp, loc, curr, block);
#ifdef DEBUG
      std::cout << "\033[32m     After: \033[39m";
      for (size_t i = 0; i < tmp.size() / block; i++) {
        for (size_t j = 0; j < block; j++)
          std::cout << tmp[i * block + j] << " ";
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
  std::cout << "\033[33m Out for " << block << ":  \033[39m";
  for (size_t i = 0; i < tmp.size() / block; i++) {
    for (size_t j = 0; j < block; j++) std::cout << tmp[i * block + j] << " ";
    std::cout << "| ";
  }
  std::cout << std::endl << std::endl;
#endif

  // Copy sorted data to original array
  std::copy(tmp.begin(), tmp.end(), begin);
}

#endif