/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:18:44 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 11:52:58 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "AMateria.hpp"
#include <iostream>

class AMateria;

class ICharacter
{
public:
	virtual	~ICharacter() {}
	virtual std::string const &	getName() const = 0;
	virtual void	equip( AMateria *m ) = 0;
	virtual void	unequip( int idx ) = 0;
	virtual void	use( int idx, ICharacter& target ) = 0;
};

#endif