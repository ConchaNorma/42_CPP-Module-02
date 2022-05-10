/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:38:39 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/10 19:57:29 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const int intValue);
	Fixed(const float floatValue);
	Fixed(const Fixed &fixed);
	Fixed& operator= (const Fixed &fixed);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	bool operator == (const Fixed &other);
	bool operator!= (const Fixed &other);
	bool operator> (const Fixed &other) const;
	bool operator< (const Fixed &other) const;
	bool operator>= (const Fixed &other) const;
	bool operator<= (const Fixed &other) const;
	Fixed operator+ (const Fixed &other);
	Fixed operator- (const Fixed &other);
	Fixed operator* (const Fixed &other);
	Fixed operator/ (const Fixed &other);
	Fixed& operator++ ();
	Fixed operator++ (int);
	Fixed& operator-- ();
	Fixed operator-- (int);

	static const Fixed& max( Fixed const &a,  Fixed const &b);
	static Fixed& max( Fixed &a,  Fixed &b);
	static const Fixed& min( Fixed const &a,  Fixed const &b);
	static Fixed& min( Fixed &a,  Fixed &b);

private:
	int fixed_number;
	static const int fractional_bits = 8;
};

std::ostream &operator<< (std::ostream &out, const Fixed &fix);

#endif
