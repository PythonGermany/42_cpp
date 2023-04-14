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

void ft_replace(std::string& s, std::string oldInsert, std::string newInsert)
{
	std::string buf;
	std::size_t i = 0;
	std::size_t iPrev;

	buf.reserve(s.size());
	while (true)
	{
		iPrev = i;
		i = s.find(oldInsert, i);
		if (i == std::string::npos)
			break;
		buf.append(s, iPrev, i - iPrev);
		buf += newInsert;
		i += oldInsert.size();
	}
	buf.append(s, iPrev, s.size() - iPrev);
	s.swap(buf);
}

int main(int argc, char** argv)
{
	std::string read;
	std::ifstream in;
	std::ofstream out;
	std::string outfile;

	if (argc != 4)
		return (std::cout << "Use: " << argv[0] << " <filename> <s1> <s2>" << std::endl, 1);
	if (std::string(argv[2]).length() < 1)
		return (std::cout << "An empty string is not allowed for <s1>" << std::endl, 1);
	in.open(argv[1], std::ifstream::in);
	if (in.fail())
		return (std::cout << "Failed to open input file" << std::endl, 1);
	outfile = argv[1];
	out.open(outfile.append(".replace").c_str(), std::ofstream::out);
	if (out.fail())
		return (std::cout << "Failed to create/open output file" << std::endl, 1);
	while (true)
	{
		std::getline(in, read);
		ft_replace(read, argv[2], argv[3]);
		out << read;
		if (in.eof())
			break;
		else
			out << "\n";
	}
	in.close();
	out.close();
	return (0);
}
