/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:25:35 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:33:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

int main(int argc, char** argv) {
  if (argc < 2)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else
    while (*++argv != NULL)
      while (**argv != '\0') std::cout << (char)std::toupper(*(*argv)++);
  std::cout << std::endl;
  return (0);
}
