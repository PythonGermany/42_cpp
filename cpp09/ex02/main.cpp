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

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2) PmergeMe::handleError("Wrong argument count", 1);
  std::vector<std::string> arg(argc - 1);
  for (int i = 0; i < argc - 1; i++) arg[i] = argv[i + 1];
  PmergeMe p(arg);
  std::cout << "Container one before: ";
  p.printContainerOne();
  std::cout << "Container two before: ";
  p.printContainerTwo();
  std::string timeOne = p.sortContainerOne();
  std::string timeTwo = p.sortContainerTwo();
  std::cout << "Container one after: ";
  p.printContainerOne();
  // std::cout << "Container two after: ";
  // p.printContainerTwo();
  std::cout << "Container one time: " << timeOne << "us" << std::endl;
  // std::cout << "Container two time: " << timeTwo << "ms" << std::endl;
}