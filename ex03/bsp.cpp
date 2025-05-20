/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 06:40:12 by kmummadi          #+#    #+#             */
/*   Updated: 2025/05/20 07:03:00 by kmummadi         ###   ########.fr       */
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
