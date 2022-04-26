/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:38:39 by cnorma            #+#    #+#             */
/*   Updated: 2022/04/26 22:39:35 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	Fixed& operator= (const Fixed &other);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	bool operator == (const Fixed &other);
	bool operator!= (const Fixed &other);
	bool operator> (const Fixed &other);
	bool operator< (const Fixed &other);
	bool operator>= (const Fixed &other);
	bool operator<= (const Fixed &other);
	Fixed operator+ (const Fixed &other);
	Fixed operator- (const Fixed &other);
	Fixed operator* (const Fixed &other);
	Fixed operator/ (const Fixed &other);
	Fixed& operator++ ();
	Fixed operator++ (int value);

private:
	int fixed_number;
	static const int fractional_bits = 8;
};

std::ostream &operator<< (std::ostream &out, const Fixed &fix);

#endif
