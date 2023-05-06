/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:28:26 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 20:15:14 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b;
	Bureaucrat c;

	try
	{
		b = new Bureaucrat("Test1", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		b = new Bureaucrat("Test1", 156);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		b = new Bureaucrat("Test1", 12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for (size_t i = 0; i < 12; i++)
	{
		try
		{
			b->incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << *b << std::endl;
	}
	delete b;
	std::cout << std::endl;

	try
	{
		c = Bureaucrat("Test2", 145);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << c << std::endl;
	c.decrementGrade();
	std::cout << c << std::endl;
	for (size_t i = 0; i < 5; i++)
	{
		try
		{
			c.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << c << std::endl;
	}
}