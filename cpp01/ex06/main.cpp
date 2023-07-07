/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:49:44 by rburgsta          #+#    #+#             */
/*   Updated: 2023/02/17 15:32:14 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void filter(Harl *h, int i, std::string* lvls)
{
	for (; i < 4; i++)
		h->complain(lvls[i]);
}

int main(int argc, char **argv)
{
	Harl h;
	int i;
	std::string filterLVL[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
		return (std::cout << "use: " << argv[0] << " [filter level]" << std::endl, 1);
	for (i = 0; i < 4; i++)
		if (!filterLVL[i].compare(argv[1]))
			break;
	switch (i)
	{
	case 0:
		filter(&h, i, filterLVL);
		break;
	case 1:
		filter(&h, i, filterLVL);
		break;
	case 2:
		filter(&h, i, filterLVL);
		break;
	case 3:
		filter(&h, i, filterLVL);
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
