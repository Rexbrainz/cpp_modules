/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:41:02 by kmummadi          #+#    #+#             */
/*   Updated: 2025/05/19 14:50:10 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

struct Point
{
    Point(void);
    Point(const float, const float);
    Point(const Point&);
    ~Point(void);
    //Operators
    void  operator=(const Point&);
    const Fixed&    getXCoord(void) const;
    const Fixed&    getYCoord(void) const;
  private:
    Fixed const x;
    Fixed const y;
};

Point   operator-(const Point&, const Point&);
Fixed   crossProduct(const Point&, const Point&);
bool    bsp(Point const, Point const, Point const, Point const);


#endif
