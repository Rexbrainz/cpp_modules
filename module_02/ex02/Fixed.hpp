/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:45:00 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/15 13:56:14 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

struct	Fixed
{
  //constructors
	Fixed(void);
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed&);
	~Fixed(void);
 //operations
	Fixed&	operator=(const Fixed&);
    bool    operator>(const Fixed&) const;
    bool    operator<(const Fixed&) const;
    bool    operator>=(const Fixed&) const;
    bool    operator<=(const Fixed&) const;
    bool    operator==(const Fixed&) const;
    bool    operator!=(const Fixed&) const;
    Fixed   operator+(const Fixed&) const;
    Fixed&  operator+=(const Fixed&);
    Fixed   operator-(const Fixed&) const;
    Fixed&  operator-=(const Fixed&);
    Fixed   operator*(const Fixed&) const;
    Fixed&  operator*=(const Fixed&);
    Fixed   operator/(const Fixed&) const;
    Fixed&  operator/=(const Fixed&);
    Fixed   operator++(int);
    Fixed   operator--(int);
    Fixed&  operator++(void);
    Fixed&  operator--(void);
  //member functions
	int		            getRawBits(void) const;
	void	            setRawBits(int const raw);
	float	            toFloat(void) const;
	int                 toInt(void) const;
    static Fixed&       min(Fixed&, Fixed&);
    static const Fixed& min(const Fixed&, const Fixed&);
    static Fixed&       max(Fixed&, Fixed&);
    static const Fixed& max(const Fixed&, const Fixed&);
  private:
	int					fpnValue;
	static const int	fBits;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& rightOperand);

#endif
