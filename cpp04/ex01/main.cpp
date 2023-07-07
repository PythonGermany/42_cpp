/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:25:11 by rburgsta          #+#    #+#             */
/*   Updated: 2023/03/08 19:47:27 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	size_t array_size = 4;
	Animal *a[array_size];
	size_t i = 0;
	
	std::cout << "\x1B[31mConstruct array:\x1B[0m" << std::endl;
	for (; i < array_size / 2; i++)
		a[i] = new Dog();
	for (; i < array_size; i++)
		a[i] = new Cat();
	std::cout << std::endl << "\x1B[31mDelete arrray:\x1B[0m" << std::endl;
	while (i-- > 0)
		delete a[i];
	std::cout << std::endl << "\x1B[31mDog & Cat Construction:\x1B[0m" << std::endl;
	Dog x;
	Cat z;
	std::cout << std::endl << "\x1B[31mDog & Cat Copy:\x1B[0m" << std::endl;
	Dog y(x);
	Cat c(z);
	std::cout << std::endl << "\x1B[31mDog & Cat destruction:\x1B[0m" << std::endl;
	//system("leaks ex01");
	return 0;
}