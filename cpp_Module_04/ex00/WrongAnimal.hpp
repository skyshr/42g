/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:56:41 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 10:28:49 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
private:
	std::string	_type;
	
public:
	WrongAnimal();
	WrongAnimal( std::string type );

	~WrongAnimal( void );
	WrongAnimal( const WrongAnimal& obj );
	WrongAnimal& operator=( const WrongAnimal& obj );

	void	makeSound( void ) const;
	std::string		getType( void ) const;

};

#endif