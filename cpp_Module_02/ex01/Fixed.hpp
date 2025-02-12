/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:15:01 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 17:00:00 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_val;
	static const int	_bits = 8;

public:
	Fixed();
	Fixed( const int i );
	Fixed( const float f );
	~Fixed();
	Fixed( const Fixed &obj );
	Fixed& operator= ( const Fixed &obj );
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void )	const;
};

std::ostream& operator<< ( std::ostream &o, Fixed const &i );

#endif