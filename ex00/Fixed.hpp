/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:45:14 by marudlof          #+#    #+#             */
/*   Updated: 2026/08/03 14:45:16 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;

	public:
		Fixed( );
		Fixed( const Fixed &other );
		Fixed &operator=( const Fixed &other );
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
