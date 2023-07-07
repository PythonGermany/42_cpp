/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:57:52 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:42:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat {
 private:
  const std::string name;
  int grade;

 public:
  Bureaucrat();
  Bureaucrat(std::string name, int const grade);
  Bureaucrat(Bureaucrat const& rhs);
  Bureaucrat& operator=(Bureaucrat const& rhs);
  ~Bureaucrat();

  std::string const& getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs);

#endif