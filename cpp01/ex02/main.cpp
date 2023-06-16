/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:32:04 by rburgsta          #+#    #+#             */
/*   Updated: 2022/12/15 19:32:04 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string* stringPTR = &str;
  std::string& stringREF = str;

  std::cout << &str << std::endl;
  std::cout << stringPTR << std::endl;
  std::cout << &stringREF << std::endl;
  std::cout << str << std::endl;
  std::cout << *stringPTR << std::endl;
  std::cout << stringREF << std::endl;
}
