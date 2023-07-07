/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:56:32 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/30 16:56:32 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <vector>

class PmergeMe
{
private:
	std::vector<int> vec;
public:
	PmergeMe();
	PmergeMe(std::string seq);
	PmergeMe(PmergeMe const& rhs);
	PmergeMe& operator=(PmergeMe const& rhs);
	~PmergeMe();

	void loadSequence(std::string &seq);
	static void handleError(std::string msg, int exitCode);
private:
	int verifyValue(std::string &value);
};

#endif