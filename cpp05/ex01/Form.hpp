/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:17:31 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 20:17:31 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat;

class Form
{
private:
	std::string const name;
	bool isSigned;
	int const signReq;
	int const exeReq;
public:
	Form();
	Form(std::string name, int sR, int const eR);
	Form(Form const& rhs);
	Form& operator=(Form const& rhs);
	~Form();

	std::string const& getName() const;
	bool const& getSigned() const;
	int const& getSignReq() const;
	int const& getExeReq() const;

	void beSigned(Bureaucrat const& b);

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, Form const& rhs);

#endif