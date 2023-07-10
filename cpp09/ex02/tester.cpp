/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:18:59 by rburgsta          #+#    #+#             */
/*   Updated: 2023/07/10 20:01:14 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <deque>
#include <iostream>
#include <random>
#include <vector>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc != 3) return 1;
  int arr[] = {0,  1,  3,  5,  7,  10, 13, 16, 19, 22, 26,
               30, 34, 38, 42, 46, 50, 54, 58, 62, 66, 71};
  std::vector<int> worst_case(std::begin(arr), std::end(arr));
  int sizes = std::atoi(argv[1]);
  int iterations = std::atoi(argv[2]);
  PmergeMe p;
  bool error = false;
  std::random_device rd;
  std::mt19937 g(rd());
  std::vector<int> vec;

  for (int i = 0; !error && i < sizes; i++) {
    vec.push_back(i + 1);
    for (int k = 0; !error && k < iterations; k++) {
      std::vector<int> temp = vec;
      std::shuffle(temp.begin(), temp.end(), g);
      p.mergeInsertSort<std::vector<int> >(temp.begin(), temp.end(), 1);
      if (i < worst_case.size() && worst_case[i] < p.compCount) {
        std::cout << "Error for size " << i + 1
                  << " comparisions: " << p.compCount
                  << " max: " << worst_case[i] << " Output: ";
        p.printContainer(temp);
        std::cout << std::endl;
        error = true;
      }
      if (temp != vec) {
        std::cout << "Error: Wrong output: ";
        p.printContainer(temp);
        error = true;
      }
      p.compCount = 0;
    }
  }
}