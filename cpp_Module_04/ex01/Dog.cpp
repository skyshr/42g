/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:27:07 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/27 17:24:16 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	try {
		this->_brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Memory Allocation failed : " << e.what() << std::endl;
	}
	
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( Dog const &obj )
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog &Dog::operator= ( const Dog &obj )
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
		this->_brain = new Brain( *obj._brain );
	}
	return *this;
}

Dog::~Dog()
{
	delete this->_brain;
	
	std::cout << "Dog destructor called" << std::endl;
}    

void	Dog::makeSound( void ) const
{
	std::cout << "Woof Woof!!" << std::endl;
}