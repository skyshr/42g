/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:40:21 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/27 23:01:15 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( const std::string &name ) : _name( name )
{
	for ( int i = 0; i < 4; i++ )
		this->_inventory[i] = NULL;
		
	std::cout << "Character " << this->_name << " is created" << std::endl;
}

Character::Character( const Character &obj ) : _name( obj._name )
{
	std::cout << "Character copy constructor created " << this->_name << std::endl;

	*this = obj;
}

Character& Character::operator= ( const Character &obj )
{
	if ( this != &obj )
	{
		this->_name = obj._name;
		for ( int i = 0; i < 4; i++ )
			this->_inventory[i] = obj._inventory[i];
	}
	std::cout << "Character copy assignment created " << this->_name << std::endl;
	return *this;
}

Character::~Character()
{
	std::cout << "Character " << this->_name << " is destroyed" << std::endl;
	for ( int i = 0; i < 4; i++ )
		if ( this->_inventory[i] )
			delete this->_inventory[i];
}


void	Character::equip( AMateria *m )
{
	for ( int i = 0; i < 4; i++ )
		if ( this->_inventory[i] == NULL )
		{
			this->_inventory[i] = m;
			std::cout << "Character " << this->_name << " is equipped with " << m->getType() << std::endl;
			return;
		}
	std::cout << "Character " << this->_name << " is unable to equip" << m->getType() << std::endl;
}

void	Character::unequip( int idx )
{
	if ( this->_inventory[idx] == NULL )
		std::cout << "Character " << this->_name << " failed to unequip" << std::endl;
	else
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
		std::cout << "Character " << this->_name << " unequipped successfully" << std::endl;
	}
}

void	Character::use( int idx, ICharacter &target )
{
	if ( this->_inventory[idx] == NULL )
		std::cout << "Character " << this->_name << " failed to use" << std::endl;
	else
	{
		this->_inventory[idx]->use(target);
		std::cout << "Character " << this->_name << " uses " << this->_inventory[idx]->getType() << std::endl;
	}
}

std::string const & Character::getName() const 
{
	return this->_name;
}