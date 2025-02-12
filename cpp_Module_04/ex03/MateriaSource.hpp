/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:14:51 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 12:33:34 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	_materias[4];

public:
	MateriaSource();
	MateriaSource( const MateriaSource &obj );
	MateriaSource& operator= ( const MateriaSource &obj );
	~MateriaSource();

	AMateria*	createMateria( std::string const & type );
	void		learnMateria( AMateria* );
};

#endif