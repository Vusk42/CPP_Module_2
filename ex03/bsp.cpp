/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 10:28:30 by marudlof          #+#    #+#             */
/*   Updated: 2026/08/11 10:31:37 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c)
{
	return ((b.getX() - a.getX()) * (c.getY() - a.getY())
		- (c.getX() - a.getX()) * (b.getY() - a.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed const	zero(0);
	Fixed		d1 = area(a, b, point);
	Fixed		d2 = area(b, c, point);
	Fixed		d3 = area(c, a, point);

	if (d1 == zero || d2 == zero || d3 == zero)
		return (false);

	bool hasNeg = (d1 < zero) || (d2 < zero) || (d3 < zero);
	bool hasPos = (d1 > zero) || (d2 > zero) || (d3 > zero);

	return (!(hasNeg && hasPos));
}
