/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:38:35 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 11:21:03 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	const Animal	*i = new Dog();
	const Animal	*j = new Cat();

	std::cout << std::endl;

	delete i;
	delete j;

	std::cout << std::endl;

	const Animal* animal[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete animal[i];

	std::cout << std::endl;

	return 0;
}