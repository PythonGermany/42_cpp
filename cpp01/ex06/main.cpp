/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:49:44 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:36:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
  Harl h;
  int i;
  std::string filterLVL[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  if (argc != 2)
    return (std::cout << "use: " << argv[0] << " [filter level]" << std::endl,
            1);
  for (i = 0; i < 4; i++)
    if (!filterLVL[i].compare(argv[1])) break;
  switch (i) {
    case 0:
      std::cout << "[DEBUG]" << std::endl;
      h.complain("DEBUG");
      std::cout << std::endl;
      std::cout << "[INFO]" << std::endl;
      h.complain("INFO");
      std::cout << std::endl;
      std::cout << "[WARNING]" << std::endl;
      h.complain("WARNING");
      std::cout << std::endl;
      std::cout << "[ERROR]" << std::endl;
      h.complain("ERROR");
      break;
    case 1:
      std::cout << "[INFO]" << std::endl;
      h.complain("INFO");
      std::cout << std::endl;
      std::cout << "[WARNING]" << std::endl;
      h.complain("WARNING");
      std::cout << std::endl;
      std::cout << "[ERROR]" << std::endl;
      h.complain("ERROR");
      break;
    case 2:
      std::cout << "[WARNING]" << std::endl;
      h.complain("WARNING");
      std::cout << std::endl;
      std::cout << "[ERROR]" << std::endl;
      h.complain("ERROR");
      break;
    case 3:
      std::cout << std::endl;
      std::cout << "[ERROR]" << std::endl;
      h.complain("ERROR");
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]"
                << std::endl;
  }
  return (0);
}
