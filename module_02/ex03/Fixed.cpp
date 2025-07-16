/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:10:39 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/21 13:39:15 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fBits = 8;

//Constructors
Fixed::Fixed(void) : fpnValue(0) {}

Fixed::Fixed(const Fixed& other) : fpnValue(other.getRawBits()) {}

Fixed::Fixed(const int ival) : fpnValue(ival << fBits) {}

Fixed::Fixed(const float fval) : 
    fpnValue(static_cast<int>(roundf(fval * (1 << fBits)))){}

//Destructor
Fixed::~Fixed(void) {}

//Overloaded Operators
Fixed&	Fixed::operator=(const Fixed& rhs)
{
	fpnValue = rhs.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& rightOperand)
{
	os << rightOperand.toFloat();
    return (os);
}

bool    Fixed::operator>(const Fixed& rightOperand) const
{
    return (fpnValue > rightOperand.fpnValue);
}

bool    Fixed::operator<(const Fixed& rightOperand) const
{
    return (fpnValue < rightOperand.fpnValue);
}

bool    Fixed::operator>=(const Fixed& rOperand) const
{
    return (fpnValue >= rOperand.fpnValue);
}

bool    Fixed::operator<=(const Fixed& rOperand) const
{
    return (fpnValue <= rOperand.fpnValue);
}

bool    Fixed::operator==(const Fixed& ro) const
{
    return (fpnValue == ro.fpnValue);
}

bool    Fixed::operator!=(const Fixed& ro) const
{
    return (!(*this == ro));
}

Fixed   Fixed::operator+(const Fixed& ro) const
{
    Fixed   temp(*this);

    temp += ro;
    return (temp);
}

Fixed&   Fixed::operator+=(const Fixed& ro)
{
    fpnValue += ro.fpnValue;
    return (*this);
}

Fixed   Fixed::operator-(const Fixed& ro) const
{
    Fixed   temp(*this);

    temp -= ro;
    return (temp);
}

Fixed&  Fixed::operator-=(const Fixed& ro)
{
    fpnValue -= ro.fpnValue;
    return (*this);
}

Fixed   Fixed::operator*(const Fixed& ro) const
{
    Fixed   temp(*this);
    
    temp *= ro;
    return (temp);
}

Fixed&  Fixed::operator*=(const Fixed& ro)
{
    long long   product;

    product = fpnValue * ro.fpnValue;
    //Necessary to save the proper fixed point value of product.
    fpnValue = static_cast<int> (product >> fBits);
    return (*this);
}

Fixed   Fixed::operator/(const Fixed& ro) const
{
    Fixed   temp(*this);

    temp /= ro;
    return (temp);
}

Fixed&   Fixed::operator/=(const Fixed& ro)
{
    if (ro.fpnValue == 0)
        throw std::runtime_error("Division by zero");

    float   result;
    int     fpv;

    result = toFloat() / ro.toFloat();
    //Necessary to save the proper fixed point value of result.
    fpv = static_cast<int>(roundf(result * (1 << fBits)));
    setRawBits(fpv);
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   temp(*this);

    ++fpnValue;
    return (temp);
}

Fixed   Fixed::operator--(int)
{
    Fixed   temp(*this);

    --fpnValue;
    return (temp);
}

Fixed&  Fixed::operator++(void)
{
    ++fpnValue;
    return (*this);
}

Fixed&  Fixed::operator--(void)
{
    --fpnValue;
    return (*this);
}

//Member functions.
int	Fixed::getRawBits(void) const
{
	return (fpnValue);
}

void	Fixed::setRawBits(int const raw)
{
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

Fixed& Fixed::min(Fixed& fpnRef1, Fixed& fpnRef2)
{
    if (fpnRef1 < fpnRef2)
        return (fpnRef1);
    else
        return (fpnRef2);
}

const Fixed& Fixed::min(const Fixed& fpnRef1, const Fixed& fpnRef2)
{
    if (fpnRef1 < fpnRef2)
        return (fpnRef1);
    else
        return (fpnRef2);
}

Fixed&    Fixed::max(Fixed& fpnRef1, Fixed& fpnRef2)
{
    if (fpnRef1 > fpnRef2)
        return (fpnRef1);
    else
        return (fpnRef2);
}

const Fixed&  Fixed::max(const Fixed& fpnRef1, const Fixed& fpnRef2)
{
    if (fpnRef1 >= fpnRef2)
        return (fpnRef1);
    else
        return (fpnRef2);
}
