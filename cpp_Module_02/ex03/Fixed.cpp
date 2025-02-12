/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:15:47 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/18 18:35:25 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _val(0) 
{
	std::cout << "Fixed default constructor called" << std::endl;
}

Fixed::Fixed( const int i ) : _val( i << _bits )
{
	std::cout << "Fixed int constructor called" << std::endl;
}

Fixed::Fixed( const float f ) : _val( roundf( f * ( 1 << _bits ) ) )
{
	std::cout << "Fixed float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Fixed destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) 
{
	std::cout << "Fixed copy constructor called" << std::endl;
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Fixed copy assignment operator called" << std::endl;
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

std::ostream &operator<< ( std::ostream &o, Fixed const &i ) 
{
	o << i.toFloat();
	return o;
}

bool Fixed::operator> (const Fixed &obj) const
{
	return this->getRawBits() > obj.getRawBits();
}

bool Fixed::operator< (const Fixed &obj) const
{
	return this->getRawBits() < obj.getRawBits();
}

bool Fixed::operator>= (const Fixed &obj) const
{
	return this->getRawBits() >= obj.getRawBits();
}

bool Fixed::operator<= (const Fixed &obj) const
{
	return this->getRawBits() <= obj.getRawBits();
}

bool Fixed::operator== (const Fixed &obj) const
{
	return this->getRawBits() == obj.getRawBits();
}

bool Fixed::operator!= (const Fixed &obj) const
{
	return this->getRawBits() != obj.getRawBits();
}

Fixed Fixed::operator+ (const Fixed &obj) const
{
	return Fixed( this->toFloat() + obj.toFloat() );
}

Fixed Fixed::operator- (const Fixed &obj) const
{
	return Fixed( this->toFloat() - obj.toFloat() );
}

Fixed Fixed::operator* (const Fixed &obj) const
{
	return Fixed( this->toFloat() * obj.toFloat() );
}

Fixed Fixed::operator/ (const Fixed &obj) const
{
	return Fixed( this->toFloat() / obj.toFloat() );
}

Fixed &Fixed::operator++ ( void )
{
	++this->_val;
	return *this;
}

Fixed Fixed::operator++ ( int )
{
	Fixed	tmp( *this );
	tmp._val = this->_val++;
	return tmp;
}

Fixed &Fixed::operator-- ( void )
{
	--this->_val;
	return *this;
}

Fixed Fixed::operator-- ( int )
{
	Fixed	tmp( *this );
	tmp._val = this->_val--;
	return tmp;
}

Fixed& Fixed::min( Fixed &a, Fixed &b )
{
	return a < b ? a : b;

}
const Fixed& Fixed::min( const Fixed &a, const Fixed &b )
{
	return a < b ? a : b;

}
Fixed& Fixed::max( Fixed &a, Fixed &b )
{
	return a > b ? a : b;
}
const Fixed& Fixed::max( const Fixed &a, const Fixed &b )
{
	return a > b ? a : b;
}
