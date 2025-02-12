/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:40:24 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 11:43:41 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria	*_inventory[4];

public:
	Character( std::string const &name );
	Character( const Character &obj );
	Character& operator= ( const Character &obj );
	~Character();

	std::string const &	getName() const;
	void	equip( AMateria *m );
	void	unequip ( int idx );
	void	use( int idx, ICharacter &target );
};

#endif