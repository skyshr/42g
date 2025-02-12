/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:28:57 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/25 20:51:56 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _ep(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &obj )
{
	std::cout << "ClapTrap " << this->_name << " copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap &ClapTrap::operator= ( const ClapTrap &obj )
{
	std::cout << "ClapTrap " << this->_name << " copy assignment operator called" << std::endl;
	this->_name = obj._name;
	this->_hp = obj._hp;
	this->_ep = obj._ep;
	this->_attackDamage = obj._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

void	ClapTrap::attack( const std::string &target )
{
	if ( !this->_ep )
		std::cout << "ClapTrap " << this->_name << "does not have any ep left" << std::endl;
	else
	{
		this->_ep--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " \
				<< this->_attackDamage	<< " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if ( !this->_hp )
		std::cout << "ClapTrap " << this->_name << " is already dead:(" << std::endl;
	else
	{
		this->_hp = std::max( 0, static_cast<int>( this->_hp - amount ) );
		std::cout << "ClapTrap " << this->_name << " has gotten " << amount << " damage!" << std::endl;
		std::cout << "Current hp, ep: " << this->_hp << " " << this->_ep << std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if ( !this->_ep )
		std::cout << "ClapTrap " << this->_name << "does not have any ep left" << std::endl;
	else
	{
		this->_ep--;
		this->_hp += amount;
		std::cout << "ClapTrap " << this->_name << " has gotten " << amount << " hp!" << std::endl;
		std::cout << "Current hp, ep: " << this->_hp << " " << this->_ep << std::endl;
	}
}