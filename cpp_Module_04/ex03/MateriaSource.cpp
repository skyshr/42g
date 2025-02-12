/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:29:54 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 11:36:27 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for ( int i = 0; i < 4; i++ )
		_materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for ( int i = 0; i < 4; i++ )
		if ( _materias[i] )
			delete _materias[i];
}

MateriaSource::MateriaSource( const MateriaSource &obj )
{
	*this = obj;
}

MateriaSource& MateriaSource::operator= ( const MateriaSource &obj )
{
	if (this != &obj )
	{
		for ( int i = 0; i < 4; i++ )
			_materias[i] = obj._materias[i];
	}
	return *this;
}

void	MateriaSource::learnMateria( AMateria *m )
{
	for ( int i = 0; i < 4; i++ )
		if ( _materias[i] == NULL )
		{
			_materias[i] = m;
			return ;
		}
}

AMateria*	MateriaSource::createMateria( std::string const& type )
{
	for (int i = 0; i < 4; i++)
		if ( _materias[i] && _materias[i]->getType() == type )
			return _materias[i]->clone();
	return NULL;
}