/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:28:36 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 21:28:36 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <time.h>

#include <cstdlib>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  std::string target;

 public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string const& target);
  RobotomyRequestForm(RobotomyRequestForm const& rhs);
  RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);
  ~RobotomyRequestForm();

  void executeFormTask() const;
};

#endif