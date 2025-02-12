/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:03:02 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/27 17:10:40 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string	_ideas[100];

public:
	Brain();
	Brain( const Brain& obj );
	Brain& operator=( const Brain& obj );
	~Brain();

};

#endif