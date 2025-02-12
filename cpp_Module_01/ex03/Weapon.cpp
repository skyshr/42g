/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:39:52 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/15 09:51:13 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	_type = type;
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::getType( void )
{
	return	_type;
}

void	Weapon::setType( std::string newType )
{
	_type = newType;
}