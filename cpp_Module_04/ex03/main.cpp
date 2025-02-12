/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:37:35 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 11:54:25 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource(); 
	src->learnMateria( new Ice() ); 
	src->learnMateria( new Cure() );

	ICharacter* me = new Character( "me" );

	AMateria* tmp; 
	tmp = src->createMateria( "ice" ); 
	me->equip( tmp ); 
	tmp = src->createMateria( "cure" ); 
	me->equip( tmp );

	ICharacter* bob = new Character( "bob" );

	me->use( 0, *bob ); 
	me->use( 1, *bob );
	
	delete bob; 
	delete me; 
	delete src;
	
	return 0; 
}