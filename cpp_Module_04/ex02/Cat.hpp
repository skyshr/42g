/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:27:04 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/27 17:17:47 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain*	_brain;

public:
	Cat();
	Cat( const Cat &obj );
	Cat& operator= ( const Cat &obj );
	~Cat();

	void	makeSound( void ) const;

};

#endif