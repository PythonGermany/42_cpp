/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:53:03 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/30 16:53:03 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <vector>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2) PmergeMe::handleError("Wrong argument count", 1);
  PmergeMe p;
  std::vector<int> vec;
  std::deque<int> que;
  std::vector<std::string> arg(argc - 1);

  for (int i = 0; i < argc - 1; i++) {
    arg[i] = argv[i + 1];
    if (arg[i].size() >= 10 && arg[i].compare("2147483647") > 0)
      PmergeMe::handleError("Argument overflow", 1);
  }
  p.loadSequence(arg, vec, que);
  std::cout << "Container before: ";
  p.printContainer(vec);
  std::string timeOne = p.sortContainer(vec);
#ifndef DEBUG
  std::string timeTwo = p.sortContainer(que);
#endif
  std::cout << "Container after:  ";
  p.printContainer(vec);
  std::cout << "Container vector time for " << arg.size()
            << " elements: " << timeOne << "ms" << std::endl;
#ifndef DEBUG
  std::cout << "Container dqueue time for " << arg.size()
            << " elements: " << timeTwo << "ms" << std::endl;
#endif
#ifdef COUNT
  std::cout << p.compCount * 0.5 << std::endl;
#endif
}