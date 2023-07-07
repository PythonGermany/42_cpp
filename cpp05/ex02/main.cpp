/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:28:26 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:43:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  // AForm f("AForm", 1, 1);
  ShrubberyCreationForm s("ShrubberyCreationFormTest1");
  RobotomyRequestForm r("RobotomyRequestFormTest1");
  PresidentialPardonForm p("PresidentialPardonFormTest1");
  Bureaucrat b("BureaucratTest1", 1);
  Bureaucrat b2("BureaucratTest2", 146);
  Bureaucrat b3("BureaucratTest3", 72);
  Bureaucrat b4("BureaucratTest4", 26);

  std::cout << std::endl;
  b.executeForm(s);
  b2.executeForm(s);
  b2.signForm(s);
  b.signForm(s);
  b2.executeForm(s);
  b.executeForm(s);
  std::cout << std::endl;

  b2.signForm(r);
  b3.signForm(r);
  b3.executeForm(r);
  b.executeForm(r);
  std::cout << std::endl;

  b2.signForm(p);
  b3.signForm(p);
  b4.signForm(p);
  b.executeForm(p);
  b.signForm(p);
  b.executeForm(p);
  std::cout << std::endl;
}