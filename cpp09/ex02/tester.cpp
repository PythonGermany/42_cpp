/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:18:59 by rburgsta          #+#    #+#             */
/*   Updated: 2023/07/11 15:00:43 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <deque>
#include <iostream>
#include <random>
#include <vector>

#include "PmergeMe.hpp"

template <typename T>
void runTest(size_t range, size_t iterations) {
  int arr[] = {0,  1,  3,  5,  7,  10, 13, 16, 19, 22, 26,
               30, 34, 38, 42, 46, 50, 54, 58, 62, 66, 71};
  std::vector<int> worst_case(std::begin(arr), std::end(arr));
  std::random_device rd;
  std::mt19937 g(rd());
  PmergeMe p;
  T data;

  for (int i = 0; i < range; i++) {
    data.push_back(i + 1);
    for (int k = 0; k < iterations; k++) {
      T temp = data;
      std::shuffle(temp.begin(), temp.end(), g);
      p.mergeInsertSort<T>(temp.begin(), temp.end(), 1);
      if (i < worst_case.size() && worst_case[i] < p.compCount) {
        std::cout << "Error for size " << i + 1
                  << " comparisions: " << p.compCount
                  << " max: " << worst_case[i] << " Output: ";
        p.printContainer(temp);
        std::cout << std::endl;
        std::exit(1);
      }
      if (temp != data) {
        std::cout << "Error: Wrong output: ";
        p.printContainer(temp);
        std::exit(1);
      }
      p.compCount = 0;
    }
  }
}

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " <range> <iterations>" << std::endl;
    return 1;
  }
  int range = std::atoi(argv[1]);
  int iterations = std::atoi(argv[2]);

  runTest<std::vector<int> >(range, iterations);
  std::cout << "std::vector<int> OK" << std::endl;
  runTest<std::deque<int> >(range, iterations);
  std::cout << "std::deque<int> OK" << std::endl;
}