/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:42:09 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:33:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : initialized(false) { return; }

Contact::~Contact(void) { return; }

static std::string get_user_input(std::string prompt) {
  std::string input;

  while (true) {
    std::cout << prompt;
    std::getline(std::cin, input);
    if (input.length() < 1)
      std::cout << "ERROR: A saved contact can’t have empty fields!"
                << std::endl;
    else
      break;
  }
  return input;
}

void Contact::init(void) {
  this->first_name = get_user_input("Enter first name:     |> ");
  this->last_name = get_user_input("Enter last name:      |> ");
  this->nickname = get_user_input("Enter nickname:       |> ");
  this->phone_number = get_user_input("Enter phone number:   |> ");
  this->darkest_secret = get_user_input("Enter darkest secret: |> ");
  this->initialized = true;
}

static void printColumn(std::string data, bool last) {
  if (data.length() > 10) {
    data.erase(9, std::string::npos);
    data.append(".");
  }
  for (int i = 0; i < 10 - (int)data.length(); i++) std::cout << " ";
  if (last == false)
    std::cout << data << "|";
  else
    std::cout << data << std::endl;
}

void Contact::column(void) {
  if (this->initialized == false) return;
  printColumn(this->first_name, false);
  printColumn(this->last_name, false);
  printColumn(this->nickname, true);
}

void Contact::print(void) {
  if (this->initialized == false) return;
  std::cout << "First name:     |> " << this->first_name << std::endl;
  std::cout << "Last name:      |> " << this->last_name << std::endl;
  std::cout << "Nickname:       |> " << this->nickname << std::endl;
  std::cout << "Phone number:   |> " << this->phone_number << std::endl;
  std::cout << "Darkest secret: |> " << this->darkest_secret << std::endl;
}

bool Contact::getInitialized(void) { return (this->initialized); }
