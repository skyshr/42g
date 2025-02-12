/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:26:58 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 11:35:15 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( std::string type ) : _type( type )
{
	std::cout << "Animal " << this->_type << " constructor called" << std::endl;
}

Animal::Animal( Animal const &obj )
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
}

Animal &Animal::operator= ( const Animal &obj )
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return this->_type;
}

void Animal::makeSound( void ) const
{
	std::cout << "Animal makeSound function called" << std::endl;
}
