/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:08:58 by rburgsta          #+#    #+#             */
/*   Updated: 2023/03/09 18:11:43 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : iMateria(0)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const& src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& rhs)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	while (iMateria-- > 0)
		delete materia[iMateria];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (iMateria < 4)
		materia[iMateria++] = m->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < iMateria; i++)
		if (materia[i]->getType() == type)
			return (materia[i]->clone());
	return (NULL);
}