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
	int value;
} t_element;


class RPN
{
private:
	std::list<t_element> data;
	std::list<t_element> stack;
public:
	RPN();
	RPN(std::string expr);
	RPN(RPN const& rhs);
	RPN& operator=(RPN const& rhs);
	~RPN();

	void loadExpression(std::string expr);
	int processExpression();
	static void handleError(std::string msg, int exitCode);
};

#endif