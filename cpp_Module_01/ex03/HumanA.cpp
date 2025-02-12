/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:18:18 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/16 15:36:34 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack( void ) const
{
	if (_weapon.getType() != "")
		std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
	else
		std::cout << _name << " doesn't have a weapon" << std::endl;
}
