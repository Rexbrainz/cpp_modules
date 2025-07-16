/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:10:39 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/15 14:01:53 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fBits = 8;

Fixed::Fixed(void) : fpnValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : fpnValue(other.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int ival) : fpnValue(ival << fBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fval) : fpnValue(static_cast<int>(roundf(fval * (1 << fBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fpnValue = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fpnValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fpnValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (fpnValue / static_cast<float>(1 << fBits));
}

int		Fixed::toInt(void) const
{
	return (fpnValue >> fBits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& rightOperand)
{
	os << rightOperand.toFloat();
    return (os);
}
