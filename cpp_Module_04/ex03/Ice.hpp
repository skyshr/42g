/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:22:59 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 12:33:16 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:

public:
	Ice();
	Ice ( const Ice &obj );
	Ice& operator= ( const Ice &obj );
	~Ice();

	AMateria*	clone() const;
	void		use( ICharacter& target );
};

#endif