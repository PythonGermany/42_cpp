/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:25:11 by rburgsta          #+#    #+#             */
/*   Updated: 2023/04/15 16:16:08 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	//AAnimal a;
	Cat c;
	Dog d;
	c.getType();
	c.makeSound();
	d.getType();
	d.makeSound();
	//system("leaks ex02");
	return 0;
}