/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:29:58 by rburgsta          #+#    #+#             */
/*   Updated: 2023/04/14 17:47:00 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *b;
public:
	Cat();
	Cat(Cat const& rhs);
	Cat& operator=(Cat const& rhs);
	~Cat();

	Brain *getBrain() const;
	void makeSound() const;
};

#endif