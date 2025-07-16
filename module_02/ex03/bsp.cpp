/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:40:51 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/21 13:41:20 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed   abP((b - a) * (point - a));
    Fixed   bcP((c - b) * (point - b));
    Fixed   caP((a - c) * (point - c));

    if (abP > Fixed(0) && bcP > Fixed(0) && caP > Fixed(0))
        return (true);
    else if (abP < Fixed(0) && bcP < Fixed(0) && caP < Fixed(0))
        return (true);
    else
        return (false);
}
