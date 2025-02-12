/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:29:00 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/25 20:50:49 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string	_name;
	int			_hp;
	int			_ep;
	int			_attackDamage;
	
	ClapTrap();
	
public:
	ClapTrap( std::string name );
	ClapTrap( ClapTrap const &obj );
	ClapTrap& operator= ( const ClapTrap &obj );
	~ClapTrap();

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};

#endif