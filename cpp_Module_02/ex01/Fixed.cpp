/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:15:47 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 17:00:08 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _val(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int i ) : _val( i << _bits )
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float f ) : _val( roundf( f * ( 1 << _bits ) ) )
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_val = obj._val;
	return *this;
}

int	Fixed::getRawBits( void ) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return _val;
}

void	Fixed::setRawBits( int const raw )
{
	_val = raw;
}

float		Fixed::toFloat( void ) const
{
	return static_cast<float>( _val ) / ( 1 << _bits );
}

int		Fixed::toInt( void ) const
{
	return _val >> _bits;
}

std::ostream& operator<< ( std::ostream &o, Fixed const &i ) 
{
	o << i.toFloat();
	return o;
}