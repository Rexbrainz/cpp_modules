/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:59:58 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/15 10:59:33 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
    Fixed	    a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed       c(12.0f);
    Fixed       d(6.0f);
    Fixed       e(3.0f);
    Fixed       f(2.0f);

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << std::endl;
    //Mine
    std::cout << b / a << std::endl;
    std::cout << "a *= b: " << (a *= b) << std::endl;
    std::cout << (c / d / e / f) << std::endl;
    std::cout << "a is now: " << (a += b) << std::endl;
    
	return (0);
}
