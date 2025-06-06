/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:36:25 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/06 17:59:57 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    allImpossibleDisplay()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

int    getInt(std::string& literal)
{
    int i;
    try
    {
        i = stoi(literal);
    }
    catch (const std::out_of_range&)
    {
        allImpossibleDisplay();
    }
   return (i);
}

float   getFloat(std::string& literal)
{
    float f;
    try
    {
        f = stof(literal);
    }
    catch (const std::out_of_range&)
    {
        allImpossibleDisplay();
    }
    return (f);
}

double   getDouble(std::string& literal)
{
    double d;

    try
    {
        d = stod(literal);
    }
    catch (const std::out_of_range&)
    {
        allImpossibleDisplay();
    }
    return (d);
}

