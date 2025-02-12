/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:27:01 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/27 17:55:23 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

class Animal
{
protected:
	std::string	_type;
	
public:
	Animal();
	Animal( std::string type );

	virtual ~Animal( void );
	Animal( const Animal& obj );
	Animal& operator=( const Animal& obj );

	virtual void	makeSound( void ) const = 0;
	std::string		getType( void ) const;
};

#endif