/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:40:31 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/21 13:41:19 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

struct Point
{
    Point(void);
    Point(const float, const float);
    Point(const Fixed&, const Fixed&);
    Point(const Point&);
    ~Point(void);
    void  operator=(const Point&);
    const Fixed&    getXCoord(void) const;
    const Fixed&    getYCoord(void) const;
  private:
    Fixed const x;
    Fixed const y;
};

Point   operator-(const Point&, const Point&);
Fixed   operator*(const Point&, const Point&);
bool    bsp(Point const, Point const, Point const, Point const);

#endif
