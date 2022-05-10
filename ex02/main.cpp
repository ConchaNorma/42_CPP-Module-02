/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:27:16 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/10 19:39:23 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "----> Check for increment/decrement" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << "----> Check for min/max" << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, 5.5f ) << std::endl;
    std::cout << Fixed::min( 0.67f, 5.5f ) << std::endl;

   Fixed c = 1000;
   Fixed d = 3.51f;
   std::cout << "----> Check for comparison operators" << std::endl;
   std::cout << "c == d " << (c == d) << std::endl;
   std::cout << "c != d " << (c != d) << std::endl;
   std::cout << "c > d " << (c > d) << std::endl;
   std::cout << "c < d " << (c < d) << std::endl;
   std::cout << "c >= d " << (c >= d) << std::endl;
   std::cout << "c <= d " << (c <= d) << std::endl;

   std::cout << "----> Check for arithmetic operators" << std::endl;
   std::cout << "c + d " << (c + d) << std::endl;
   std::cout << "c - d " << (c - d) << std::endl;
   std::cout << "c * d " << (c * d) << std::endl;
   std::cout << "c / d " << (c / d) << std::endl;

   return 0;
}
