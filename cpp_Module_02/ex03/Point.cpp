/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:31:57 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 20:51:18 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	std::cout << "Point default constructor called" << std::endl;
}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{
	std::cout << "Point float constructor called" << std::endl;
}

Point::Point( const Point &obj ) : _x(obj._x), _y(obj._y)
{
	std::cout << "Point copy constructor called" << std::endl;
}

Point &Point::operator=( const Point &obj )
{
	std::cout << "Point copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		( Fixed ) this->_x = obj._x;
		( Fixed ) this->_y = obj._y;
	}
	return *this;
}

Point::~Point()
{
	std::cout << "Point destructor called" << std::endl;
}

Fixed Point::getX( void ) const 
{
	return this->_x;
}

Fixed Point::getY( void ) const 
{
	return this->_y;
}