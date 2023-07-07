/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:29:58 by rburgsta          #+#    #+#             */
/*   Updated: 2023/04/14 18:43:15 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain *b;
public:
	Dog();
	Dog(Dog const& rhs);
	Dog& operator=(Dog const& rhs);
	~Dog();

	Brain *getBrain() const;
	void makeSound() const;
};

#endif