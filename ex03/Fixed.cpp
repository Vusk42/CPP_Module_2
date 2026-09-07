/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 10:28:16 by marudlof          #+#    #+#             */
/*   Updated: 2026/08/11 10:30:42 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) { }

Fixed::Fixed(const int n)
{
	this->_value = n << this->_fractionalBits;
}

Fixed::Fixed(const float n)
{
	this->_value = roundf(n * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() { }

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalBits);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->_value + other._value);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->_value - other._value);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;

	result.setRawBits((int)(((long)this->_value * other._value) >> this->_fractionalBits));
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	result.setRawBits((int)(((long)this->_value << this->_fractionalBits) / other._value));
	return (result);
}

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	this->_value++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	this->_value--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
