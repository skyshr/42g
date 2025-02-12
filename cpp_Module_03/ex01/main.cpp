/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:29:03 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/26 14:53:15 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	ct("jack");
	ScavTrap	st("army");

	ct.attack("dog");
	ct.takeDamage(8);
	ct.beRepaired(3);
	ct.takeDamage(5);
	ct.beRepaired(10);

	st.attack("cat");
	st.takeDamage(10);
	st.beRepaired(100);
	st.takeDamage(50);
	st.guardGate();
	
	return 0;
}