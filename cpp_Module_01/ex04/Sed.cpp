/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:15:49 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/17 09:41:14 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed( std::string filename ) : _inFile( filename )
{
	_outFile = _inFile + ".replace";
}

Sed::~Sed() 
{
}

void	Sed::replace( std::string from, std::string to )
{
	std::ifstream	fdin(_inFile.c_str());
	std::ofstream	fdout(_outFile.c_str());

	if (!fdin.is_open() || !fdout.is_open())
	{
		std::cout << "Unable to open file" << std::endl;
		return;
	}
	std::string	content;
	if (getline(fdin, content, '\0'))
	{
		size_t	pos = 0;
		while ((pos = content.find(from, pos)) != std::string::npos) 
		{
			content.erase(pos, from.length());
			content.insert(pos, to);
			pos += to.length();
		}
		fdout << content;
	}
	else
		std::cout << "Read file is empty" << std::endl;
	fdin.close();
	fdout.close();
}
