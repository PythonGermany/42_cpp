/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:53:15 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/12 17:53:15 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mst;
	std::cout << mst.size() << std::endl;
	mst.push(25);
	std::cout << mst.size() << std::endl;
	std::cout << *mst.begin() << std::endl;
	std::cout << *mst.end() << std::endl;
	return (0);
}