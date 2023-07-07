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
#include <iostream>

int main()
{
	std::vector<int> intvec;

	intvec.push_back(5);
	intvec.push_back(10);
	try
	{
		easyfind(intvec, 10);
		std::cerr << "Number found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cerr << "Number not found" << std::endl;
	}
	try
	{
		easyfind(intvec, 5);
		std::cerr << "Number found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cerr << "Number not found" << std::endl;
	}
}