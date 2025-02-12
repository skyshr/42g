/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:38:35 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/27 13:14:47 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

int	main()
{
	std::cout << "--------------- Animal Test ---------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << "type j: " << j->getType() << " " << std::endl;
	std::cout << "type i: " << i->getType() << " " << std::endl;
	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	std::cout << "--------------- Wrong Animal Test ---------------" << std::endl;
	const WrongAnimal*	neta = new WrongAnimal();
	const WrongAnimal*	c = new WrongCat();

	std::cout << std::endl;
	std::cout << "type neta: " << neta->getType() << " " << std::endl;
	std::cout << "type c: " << c->getType() << " " << std::endl;
	std::cout << std::endl;
	neta->makeSound();
	c->makeSound();
	std::cout << std::endl;
	
	delete neta;
	delete c;

	return 0;
}