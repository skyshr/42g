/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:27:09 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 11:13:46 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
	Brain*	_brain;
	
public:
	Dog();
	Dog( const Dog &obj );
	Dog& operator= ( const Dog &obj );
	~Dog();

	void	makeSound( void ) const;

};

#endif
