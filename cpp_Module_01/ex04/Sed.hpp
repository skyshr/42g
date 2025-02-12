/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:13:49 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/17 09:36:42 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
private:
	std::string	_inFile;
	std::string	_outFile;

public:
	Sed(std::string filename);
	~Sed();

	void	replace( std::string from, std::string to);
};

#endif