/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:23:02 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 09:24:50 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice instance is created" << std::endl;
}

Ice::Ice( const Ice &obj ) : AMateria("ice")
{
	std::cout << "Ice copy constructor is called" << std::endl;
	
	*this = obj;
}

Ice& Ice::operator= (const Ice &obj )
{
	std::cout << "Ice copy assignment constructor is called" << std::endl;

	if (this != &obj)
		this->_type = obj._type;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice instance is destroyed" << std::endl;
}

AMateria*	Ice::clone() const
{
	AMateria*	Materia = NULL;
	
	try {
		Materia = new Ice( *this );
	}
	catch ( const std::bad_alloc& e ) {
		std::cout << "Memory allocation failed : " << e.what() << std::endl;
	}
	
	std::cout << "Ice materia cloned succesfully" << std::endl;
	return Materia;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
