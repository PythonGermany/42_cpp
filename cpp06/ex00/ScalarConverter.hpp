/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:35:13 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/06 23:35:13 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(ScalarConverter const& rhs);
	ScalarConverter& operator=(ScalarConverter const& rhs);
	~ScalarConverter();

	static void convert(std::string literal);
private:
	static int verifyValue(std::string &value)

};

#endif