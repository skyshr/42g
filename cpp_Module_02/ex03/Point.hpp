/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:27:26 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/18 18:56:31 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point();
	Point( const float x, const float y );
	Point( const Point &obj );
	~Point();
	
	Point &operator= ( const Point &obj );

	Fixed getX( void ) const;
	Fixed getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif