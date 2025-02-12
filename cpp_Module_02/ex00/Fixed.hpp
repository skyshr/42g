/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:15:01 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 16:04:12 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_val;
	static const int	bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed( const Fixed &obj );
	Fixed& operator= ( const Fixed &obj );
	
	int		getRawBits ( void ) const;
	void	setRawBits( int const raw );
};

#endif