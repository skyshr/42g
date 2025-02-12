/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:29:03 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/26 14:59:03 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap	ct("jack");
	FragTrap	ft("frog");
	DiamondTrap	dt("dia");

	ct.attack("dog");
	ct.takeDamage(8);
	ct.beRepaired(3);
	ct.takeDamage(5);
	ct.beRepaired(10);

	ft.attack("cat");
	ft.takeDamage(120);
	ft.beRepaired(100);
	ft.takeDamage(50);
	ft.highFivesGuys();

	dt.whoAmI();
	dt.attack("hama");
	dt.highFivesGuys();
	dt.beRepaired(10);
	dt.takeDamage(88);
	dt.guardGate();

	return 0;
}