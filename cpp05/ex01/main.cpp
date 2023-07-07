/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:28:26 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/16 15:53:29 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form f("TestForm1", 13, 10);
	Bureaucrat b("TestBureaucrat1", 15);
	Bureaucrat b2("TestBureaucrat2", 13);

	std::cout << f << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;
	b2.signForm(f);
	std::cout << f << std::endl;
	std::cout << std::endl;
	f = Form("TestForm2", 15, 9);
	std::cout << f << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;
	std::cout << std::endl;
	try {
		f = Form("TestForm2", 0, 9);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		f = Form("TestForm2", 16, 160);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}