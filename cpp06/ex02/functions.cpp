/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:53:51 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/12 14:53:51 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <stdlib.h>
#include <time.h>

Base *generate(void)
{
	srand(time(NULL));
	int index = rand() % 3;
	Base *ret = NULL;

	if (index == 0)
		ret = dynamic_cast<Base*>(new A());
	else if (index == 1)
		ret = dynamic_cast<Base*>(new B());
	else
		ret = dynamic_cast<Base*>(new C());
	std::cout << index << std::endl; //Debug
	return (ret);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	(void)p;
}