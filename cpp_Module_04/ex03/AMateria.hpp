/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:45:44 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 12:32:05 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class ICharacter;

class AMateria
{
protected:
	std::string	_type;
	
public:
	AMateria();
	AMateria( std::string const & type );
	AMateria( AMateria const & src );
	virtual ~AMateria();

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void	use( ICharacter& target );
};

#endif