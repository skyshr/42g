/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:10:38 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/17 09:59:37 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef	WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string	_type;
	
public:
	Weapon( std::string type );
	~Weapon();

	const std::string&	getType( void );
	void				setType( std::string newType );
};

#endif