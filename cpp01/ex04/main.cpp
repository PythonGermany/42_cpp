/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:03:54 by rburgsta          #+#    #+#             */
/*   Updated: 2022/12/18 00:03:54 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	std::string read;
	std::fstream in;
	std::fstream out;

	if (argc != 4)
		std::cout << "Use: " << *argv << " <filename> <s1> <s2>" << std::endl;
	else
	{
		in.open(argv[1], std::ios::in);
		out.open("test2", std::ios::out);
		while (1)
		{
			in >> read;
			if (in.eof())
				break;
			out << read;
			out << "\n";
		}
		in.close();
		out.close();
	}
}
