/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:11:13 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/17 09:59:40 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef	HumanA_HPP
#define HumanA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon&		_weapon;
	HumanA();
	
public:
	HumanA( std::string name, Weapon &weapon );
	~HumanA();
	
	void	attack(void) const;
};

#endif