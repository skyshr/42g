/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:26:55 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/27 17:23:45 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	try {
		this->_brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Memory Allocation failed : " << e.what() << std::endl;
	}

	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat( Cat const &obj )
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = obj;
}

Cat &Cat::operator= ( const Cat &obj )
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
		this->_brain = new Brain( *obj._brain );
	}
	return *this;
}

void	Cat::makeSound( void ) const
{
	std::cout << "MEOW~~" << std::endl;
}
