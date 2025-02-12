/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:02:57 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/27 17:12:12 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( Brain const &obj )
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
}

Brain &Brain::operator= ( const Brain &obj )
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = obj._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}