/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:08:52 by kmummadi          #+#    #+#             */
/*   Updated: 2025/05/19 15:00:25 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const float x_c, const float y_c) : x(x_c), y(y_c) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point(void) {}

//The data members are const, which prevents us 
//from modifying the object.
void    Point::operator=(const Point& ro)
{} 

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

    return (Point(tempFixedX.toFloat(), tempFixedY.toFloat()));
}
