/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:28:36 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 21:28:36 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHUBBERYCREATIONFORM_HPP
#define SHUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string target;

 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string const& target);
  ShrubberyCreationForm(ShrubberyCreationForm const& rhs);
  ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);
  ~ShrubberyCreationForm();

  void executeFormTask() const;
};

#endif