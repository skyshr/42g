/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:00:21 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/27 21:46:20 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type( "" )
{
	std::cout << "AMateria is created " << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
	std::cout << "AMateria " << this->_type << " created" << std::endl;
}

AMateria::AMateria( AMateria const & src )
{
	*this = src;
}

AMateria::~AMateria()
{
	std::cout << "AMateria " << this->_type << " is destroyed" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

AMateria* AMateria::clone() const
{
	return (AMateria*)this;
}

void	AMateria::use( ICharacter& target )
{
	std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}