/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:43:48 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/27 21:50:32 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual	~IMateriaSource() {}
	virtual void	learnMateria( AMateria* ) = 0;
	virtual AMateria*	createMateria( std::string const & type ) = 0;
};

#endif