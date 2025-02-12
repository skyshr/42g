/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:38:35 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/28 11:31:41 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	const Animal	*i = new Dog();
	const Animal	*j = new Cat();
	// const Animal	animal = new Animal();

	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	
	std::cout << std::endl;

	delete i;
	delete j;

	std::cout << std::endl;

	return 0;
}