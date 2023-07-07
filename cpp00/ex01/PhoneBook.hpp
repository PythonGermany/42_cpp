/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:09:09 by rburgsta          #+#    #+#             */
/*   Updated: 2023/02/07 02:24:57 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <limits>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int index;
public:
	PhoneBook(void);
	~PhoneBook(void);

	void add(void);
	void search(void);
};

#endif
