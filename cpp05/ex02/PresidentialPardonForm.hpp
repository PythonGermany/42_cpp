/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:28:36 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 21:28:36 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string target;

 public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string const& target);
  PresidentialPardonForm(PresidentialPardonForm const& rhs);
  PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);
  ~PresidentialPardonForm();

  void executeFormTask() const;
};

#endif