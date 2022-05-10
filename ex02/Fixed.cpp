/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:46:45 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/10 19:39:34 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed()
{
	fixed_number = 0;
}

Fixed::Fixed(const int intValue)
{
	this->fixed_number = intValue << this->fractional_bits;
}

Fixed::Fixed(const float floatValue)
{
	this->fixed_number = roundf(floatValue * (1 << this->fractional_bits));
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed& Fixed::operator= (const Fixed &fixed)
{
	if (this == &fixed)
		return *this;
	this->fixed_number = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return (this->fixed_number);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_number = raw;
}

float Fixed::toFloat( void ) const
{
	return ((double)this->fixed_number / (double)(1 << this->fractional_bits));
}

int Fixed::toInt( void ) const
{
	return (this->fixed_number >> this->fractional_bits);
}

bool Fixed::operator == (const Fixed &other)
{
	return (this->fixed_number == other.fixed_number);
}

bool Fixed::operator!= (const Fixed &other)
{
	return !(this->fixed_number == other.fixed_number);
}

bool Fixed::operator> (const Fixed &other) const
{
	return (this->fixed_number > other.fixed_number);
}

bool Fixed::operator< (const Fixed &other) const
{
	return (this->fixed_number < other.fixed_number);
}

bool Fixed::operator>= (const Fixed &other) const
{
	return (this->fixed_number >= other.fixed_number);
}

bool Fixed::operator<= (const Fixed &other) const
{
	return (this->fixed_number <= other.fixed_number);
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
	this->fixed_number++;
	return *this;
}

Fixed Fixed::operator++ (int)
{
	Fixed temp (*this);

	this->fixed_number++;
	return temp;
}

Fixed& Fixed::operator-- ()
{
	this->fixed_number--;
	return *this;
}

Fixed Fixed::operator-- (int)
{
	Fixed temp (*this);

	this->fixed_number--;
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
