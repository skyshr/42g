/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:22:54 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 12:33:09 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:

public:
	Cure();
	Cure ( const Cure &obj );
	Cure& operator= ( const Cure &obj );
	~Cure();

	AMateria*	clone() const;
	void		use( ICharacter& target );
};

#endif