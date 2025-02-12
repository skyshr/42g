/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:46:36 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 21:00:04 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) 
{
	Fixed const p1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - \
					(b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed const p2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - \
					(c.getY() - b.getY()) * (point.getX() - b.getX());
	Fixed const p3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - \
					(a.getY() - c.getY()) * (point.getX() - c.getX());
	if (p1 > 0 && p2 > 0 && p3 > 0)
		return true;
	if (p1 < 0 && p2 < 0 && p3 < 0)
		return true;
	return false;
}