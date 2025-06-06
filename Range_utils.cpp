/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Range_utils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:21:47 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/06 17:56:03 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isFloatWithinIntRange(float value)
{
    return (value >= static_cast<float>(std::numeric_limits<int>::min()) &&
           value <= static_cast<float>(std::numeric_limits<int>::max()));
}

bool isDoubleWithinIntRange(double value)
{
    return (value >= static_cast<double>(std::numeric_limits<int>::min()) &&
           value <= static_cast<double>(std::numeric_limits<int>::max()));
}

bool isDoubleWithinFloatRange(double value)
{
    return (value >= -std::numeric_limits<float>::max() &&
           value <= std::numeric_limits<float>::max());
}

