/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:33:40 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:35:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

typedef void (Harl::*function)();

Harl::Harl(void) { return; }

Harl::~Harl(void) { return; }

void Harl::debug(void) {
  std::cout << "I love having extra bacon for my ";
  std::cout
      << "7XL-double-cheese-triple-pickle-special ketchup burger. I really do!";
  std::cout << std::endl;
}

void Harl::info(void) {
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t ";
  std::cout << "put enough bacon in my burger! If you did, I wouldn’t be "
               "asking for more!";
  std::cout << std::endl;
}

void Harl::warning(void) {
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been "
               "coming ";
  std::cout << "for years whereas you started working here since last month."
            << std::endl;
}

void Harl::error(void) {
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::complain(std::string level) {
  std::string lvlspec[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  function ptr[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

  for (size_t i = 0; i < 4; i++)
    if (lvlspec[i] == level) (this->*ptr[i])();
}
