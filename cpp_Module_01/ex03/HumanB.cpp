/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:28:23 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/13 16:09:19 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack( void ) const
{
	if (_weapon != NULL && _weapon->getType() != "")
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " doesn't have a weapon" << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	_weapon = &weapon;
}
