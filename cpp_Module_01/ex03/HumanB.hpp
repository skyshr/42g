/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:11:30 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/17 09:59:38 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef	HumanB_HPP
#define HumanB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon*		_weapon;
	
public:
	HumanB( std::string name );
	~HumanB();
	
	void	attack( void ) const;
	void	setWeapon( Weapon& weapon );
};

#endif