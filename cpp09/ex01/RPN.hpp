/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:55:08 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/30 16:55:08 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <list>
# include <string>
# include <cstring>
# include <cstdlib>
# include <iostream>

# define OPERATOR 0
# define OPERAND 1

typedef struct s_element
{
	int type;
	float value;
} t_element;

class RPN
{
public:
	RPN();
	RPN(RPN const& rhs);
	RPN& operator=(RPN const& rhs);
	~RPN();

	float processExpression(std::string expr);
	std::string postfixToInfix(std::string expr);
	static void handleError(std::string msg, int exitCode);
private:
	std::list<t_element> loadExpression(std::string &expr);
	t_element createElement(int type, float value);
	int verifyValue(std::string &value);
};

#endif