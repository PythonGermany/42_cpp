/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:07:10 by rburgsta          #+#    #+#             */
/*   Updated: 2023/06/17 00:42:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria* materia[4];
  int iMateria;

 public:
  MateriaSource();
  MateriaSource(MateriaSource const& src);
  MateriaSource& operator=(MateriaSource const& rhs);
  ~MateriaSource();

  void learnMateria(AMateria* m);
  AMateria* createMateria(std::string const& type);
};

#endif