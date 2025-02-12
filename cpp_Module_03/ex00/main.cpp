/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:29:03 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/25 19:19:33 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	ct("jack");

	ct.attack("dog");
	ct.takeDamage(8);
	ct.beRepaired(3);
	ct.takeDamage(5);
	ct.beRepaired(10);
	
	return 0;
}