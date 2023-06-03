/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:56:22 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/30 16:56:22 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string seq)
{
	loadSequence(seq);
}

PmergeMe::PmergeMe(PmergeMe const& rhs)
{
	*this = rhs;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs)
{
	if (this == &rhs)
		return (*this);
	vec = rhs.vec;
	return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::loadSequence(std::string &seq)
{
	if (seq.empty())
		handleError("Loading: Empty sequence", 1);
	vec.clear();
	//DEV clear second container
	while (seq.length() > 0)
	{
		std::string value = seq.substr(0, seq.find(' '));
		if (verifyValue(value))
			handleError("Loading: Invalid sequence", 1);
		vec.push_back(std::atoi(value.c_str()));
		//DEV add to second container
		seq.erase(0, value.size() + 1);
	}
}

int PmergeMe::verifyValue(std::string &value)
{
	if (value.empty())
		return (1);
	for (size_t i = 0; i < value.length(); i++)
		if (!std::isdigit(value[i]))
			return (1);
	return (0);
}

void PmergeMe::handleError(std::string msg, int exitCode)
{
	std::cout << "Error: " << msg << "!" << std::endl;
	std::exit(exitCode);
}