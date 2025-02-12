/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:50:59 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/17 09:33:19 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "usage: ./replace [filename] [string_from] [string_to]" << std::endl;
		return (1);
	}
	Sed	sed(argv[1]);
	sed.replace(argv[2], argv[3]);

	return (0);
}
