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
  std::cout << "Container vector before: ";
  p.printContainerOne();
  std::cout << "Container dqueue before: ";
  p.printContainerTwo();
  std::string timeOne = p.sortContainerOne();
  std::string timeTwo = p.sortContainerTwo();
  std::cout << "Container vector after:  ";
  p.printContainerOne();
  std::cout << "Container dqueue after:  ";
  p.printContainerTwo();
  std::cout << "Container vector time:   " << timeOne << "ms" << std::endl;
  std::cout << "Container dqueue time:   " << timeTwo << "ms" << std::endl;
}