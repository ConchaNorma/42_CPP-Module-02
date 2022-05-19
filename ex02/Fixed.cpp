/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:46:45 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/19 21:37:54 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed()
{
	_number = 0;
}

Fixed::Fixed(const int intValue)
{
	this->_number = intValue << this->_bits;
}

Fixed::Fixed(const float floatValue)
{
	this->_number = roundf(floatValue * (1 << this->_bits));
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed& Fixed::operator= (const Fixed &fixed)
{
	if (this == &fixed)
		return *this;
	this->_number = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return (this->_number);
}

void Fixed::setRawBits(int const raw)
{
	this->_number = raw;
}

float Fixed::toFloat( void ) const
{
	return ((double)this->_number / (double)(1 << this->_bits));
}

int Fixed::toInt( void ) const
{
	return (this->_number >> this->_bits);
}

bool Fixed::operator == (const Fixed &other)
{
	return (this->_number == other._number);
}

bool Fixed::operator!= (const Fixed &other)
{
	return !(this->_number == other._number);
}

bool Fixed::operator> (const Fixed &other) const
{
	return (this->_number > other._number);
}

bool Fixed::operator< (const Fixed &other) const
{
	return (this->_number < other._number);
}

bool Fixed::operator>= (const Fixed &other) const
{
	return (this->_number >= other._number);
}

bool Fixed::operator<= (const Fixed &other) const
{
	return (this->_number <= other._number);
}

Fixed Fixed::operator+ (const Fixed &other)
{
	return Fixed (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator- (const Fixed &other)
{
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator* (const Fixed &other)
{
		return Fixed (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/ (const Fixed &other)
{
	return Fixed (this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++ ()
{
	this->_number++;
	return *this;
}

Fixed Fixed::operator++ (int)
{
	Fixed temp (*this);

	this->_number++;
	return temp;
}

Fixed& Fixed::operator-- ()
{
	this->_number--;
	return *this;
}

Fixed Fixed::operator-- (int)
{
	Fixed temp (*this);

	this->_number--;
	return temp;
}

const Fixed& Fixed::max( Fixed const &a,  Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed& Fixed::max( Fixed &a,  Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::min( Fixed const &a,  Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::min( Fixed &a,  Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed::~Fixed(){}

std::ostream &operator<< (std::ostream &out, const Fixed  &fix)
{
	out << fix.toFloat();
	return (out);
}
