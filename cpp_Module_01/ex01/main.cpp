/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:47:16 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/15 09:40:10 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#define N 4

int	main()
{
	Zombie	*zombies = zombieHorde(N, "test_zombie");
	for (int i = 0; i < N; i++) {
		std::cout << "[ zombie " << i << " ] ";
		zombies[i].announce();
	}
	delete[] zombies;
	return 0;
}
