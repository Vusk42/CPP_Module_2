/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 10:28:33 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/07 16:02:31 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void test(Point const a, Point const b, Point const c, Point const p,
	const char *label)
{
	std::cout << label << " -> "
		<< (bsp(a, b, c, p) ? "inside" : "outside/edge") << std::endl;
}

int main(void)
{
	Point const a(0.0f, 0.0f);
	Point const b(10.0f, 0.0f);
	Point const c(0.0f, 10.0f);

	test(a, b, c, Point(2.0f, 2.0f), "Point (2, 2) is inside");
	return (0);
}
