/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:49:44 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:36:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
  Harl h;

  h.complain("DEBUG");
  std::cout << std::endl;
  h.complain("ERROR");
  std::cout << std::endl;
  h.complain("INFO");
  std::cout << std::endl;
  h.complain("WARNING");
  return (0);
}
