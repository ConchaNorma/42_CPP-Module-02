/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:46:45 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/19 21:17:22 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_number = 0;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->_number = intValue << this->_bits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->_number = roundf(floatValue * (1 << this->_bits));
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	return ((float)this->_number / (1 << this->_bits));
}

int Fixed::toInt( void ) const
{
	return (this->_number >> this->_bits);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<< (std::ostream &out, const Fixed  &fix)
{
	out << fix.toFloat();
	return (out);
}
