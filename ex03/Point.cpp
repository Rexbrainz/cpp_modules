/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:40:11 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/21 13:40:17 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const float x_c, const float y_c) : x(x_c), y(y_c) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::Point(const Fixed& X, const Fixed& Y) : x(X), y(Y) {}

Point::~Point(void) {}

//The data members are const, which prevents us 
//from modifying the object. It does nothing.
void    Point::operator=(const Point&) {} 

const Fixed&    Point::getXCoord(void) const
{
    return (x);
}

const Fixed&    Point::getYCoord(void) const
{
    return (y);
}

Point   operator-(const Point& lo, const Point& ro)
{
    Fixed   tempFixedX = ro.getXCoord() - lo.getXCoord();
    Fixed   tempFixedY = ro.getYCoord() - lo.getYCoord();

    return (Point(tempFixedX, tempFixedY));
}

Fixed   operator*(const Point& lo, const Point& ro)
{
    Fixed   x1y2 = lo.getXCoord() * ro.getYCoord();
    Fixed   y1x2 = lo.getYCoord() * ro.getXCoord();

    return (Fixed(x1y2 - y1x2));
}
