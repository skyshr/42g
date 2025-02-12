/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:57:05 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/27 13:06:18 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type )
{
	std::cout << "WrongAnimal " << this->_type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &obj )
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = obj;
}

WrongAnimal &WrongAnimal::operator= ( const WrongAnimal &obj )
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return this->_type;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal makeSound function called" << std::endl;
}
