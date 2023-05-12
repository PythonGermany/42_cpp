/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:34:40 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/08 01:34:40 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void pow(int &a)
{
	a *= a;
}

int main()
{
	int intarray[] = {0, 1, 15, 17, 84, 25, 27, 18, 74, 12, 61, 61};
	char chararray[] = "Function templates are very interesting.";
	float floatarray[] = {1.5f, 0.5f, 10.0f, 3.3f};

	iter<int, int &>(intarray, 12, pow);
	iter(intarray, 12, print<int>);
	std::cout << std::endl;
	iter(intarray, 12, pow<int>);
	iter(intarray, 12, print<int>);
	std::cout << std::endl;
	iter(intarray, 12, clear<int>);
	iter(intarray, 12, print<int>);
	std::cout << std::endl;
	iter(chararray, 41, print<char>);
	std::cout << std::endl;
	iter(chararray, 41, toUpper<char>);
	iter(chararray, 41, print<char>);
	std::cout << std::endl;
	iter(floatarray, 4, print<float>);
	std::cout << std::endl;
	iter(floatarray, 4, pow<float>);
	iter(floatarray, 4, print<float>);
	std::cout << std::endl;
	return (0);
}