/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:23:16 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/26 14:51:32 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_attackDamage = 20;
	
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void	ScavTrap::attack( const std::string &target )
{
	if ( !this->_ep )
		std::cout << "ScavTrap " << this->_name << "does not have any ep left" << std::endl;
	else
	{
		this->_ep--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " \
				<< this->_attackDamage	<< " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
