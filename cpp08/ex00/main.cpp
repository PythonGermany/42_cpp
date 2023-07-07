/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:30:25 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/08 20:30:25 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
	std::vector<int> intvec;
	std::list<int> intlist;
	std::deque<int> intdeque;

	intvec.push_back(5);
	intvec.push_back(10);
	try
	{
		easyfind(intvec, 10);
		std::cerr << "Number found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " Number not found" << std::endl;
	}
	try
	{
		easyfind(intvec, 5);
		std::cerr << "Number found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " Number not found" << std::endl;
	}
	try
	{
		easyfind(intvec, 51);
		std::cerr << "Number found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " Number not found" << std::endl;
	}
	std::cout << std::endl;

	intlist.push_back(55);
	intlist.push_back(10);
	try
	{
		easyfind(intlist, 10);
		std::cerr << "Number found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " Number not found" << std::endl;
	}
	try
	{
		easyfind(intlist, 5);
		std::cerr << "Number found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " Number not found" << std::endl;
	}
	intlist.remove(10);
	try
	{
		easyfind(intlist, 10);
		std::cerr << "Number found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " Number not found" << std::endl;
	}
	std::cout << std::endl;

	intdeque.push_back(55);
	intdeque.push_back(10);
	try
	{
		easyfind(intdeque, 10);
		std::cerr << "Number found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " Number not found" << std::endl;
	}
	try
	{
		easyfind(intdeque, 5);
		std::cerr << "Number found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " Number not found" << std::endl;
	}
	intdeque.clear();
	try
	{
		easyfind(intdeque, 10);
		std::cerr << "Number found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " Number not found" << std::endl;
	}
}