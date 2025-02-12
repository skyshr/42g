/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:22:56 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 11:55:27 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure instance is created" << std::endl;
}

Cure::Cure( const Cure &obj )
{
	std::cout << "Cure copy constructor is called" << std::endl;
	
	*this = obj;
}

Cure& Cure::operator= (const Cure &obj )
{
	std::cout << "Cure copy assignment constructor is called" << std::endl;
	
	if (this != &obj)
		this->_type = obj._type;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure instance is destroyed" << std::endl;
}
AMateria*	Cure::clone() const
{
	AMateria*	Materia;
	try {
		Materia = new Cure(*this);
	}
	catch ( const std::bad_alloc& e ) {
		std::cout << "Memory allocation failed : " << e.what() << std::endl;
	}
	
	std::cout << "Cure materia cloned succesfully" << std::endl;
	return Materia;
}


void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}