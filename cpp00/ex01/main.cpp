/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:19:00 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:33:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

int main() {
  std::string input;
  PhoneBook pb;

  while (true) {
    std::cout << "Type 'ADD', 'SEARCH' or 'EXIT': ";
    std::getline(std::cin, input);
    if (input == "ADD")
      pb.add();
    else if (input == "SEARCH")
      pb.search();
    else if (input == "EXIT")
      return (0);
  }
}
