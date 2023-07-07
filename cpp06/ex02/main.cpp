/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:34:23 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/07 21:34:23 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	Base *b = generate();
	
	identify(b);
}