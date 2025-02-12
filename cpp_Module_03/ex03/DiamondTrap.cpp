/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:36:03 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/26 15:13:58 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name ), FragTrap( name ), ScavTrap( name )
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	FragTrap::_hp = 100;
	ScavTrap::_ep = 50;
	FragTrap::_attackDamage = 30;

	std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() 
{
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
}

void	DiamondTrap::whoAmI( void ) 
{
	std::cout << "I am a DiamondTrap named " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}