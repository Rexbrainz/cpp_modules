/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:15:54 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/06 17:56:08 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    displayChar(char c)
{
    if((c >= 0 && c <= 32) || c == 127)
        std::cout << "char: Non dispayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
}

void    convertFromChar(std::string& literal)
{
    char    c = literal[0];
    if ((c >= 0 && c <= 32) || c == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void    convertFromInt(std::string& literal)
{
    int     i = getInt(literal);

    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else 
        displayChar(static_cast<char>(i));
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void    convertFromFloat(std::string& literal)
{
    float f = getFloat(literal);

    if (f < 0 || f > 127)
        std::cout << "char: impossible" << std::endl;
    else
        displayChar(static_cast<char>(f));
    if (isFloatWithinIntRange(f))
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void    convertFromDouble(std::string& literal)
{
    double d = getDouble(literal);

    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else
        displayChar(static_cast<char>(d));
    if (isDoubleWithinIntRange(d))
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    if (isDoubleWithinFloatRange(d))
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void    convertFromSpecialFloat(std::string& literal)
{
    float f = stof(literal);

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f);
}

void    convertFromSpecialDouble(std::string& literal)
{
    double d = stod(literal);

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << literal << std::endl;
}

void    ScalarConverter::convert(std::string literal)
{
    switch(detectType(literal))
    {
        case Types::Char:
            convertFromChar(literal);
            break;
        case Types::Int:   
            convertFromInt(literal);
            break;
        case Types::SpecialFloat:
            convertFromSpecialFloat(literal);
            break;
        case Types::SpecialDouble:
            convertFromSpecialDouble(literal);
            break;
        case Types::Float:   
            convertFromFloat(literal);
            break;
        case Types::Double:   
            convertFromDouble(literal);
            break;
        default:
            std::cout << "conversion not possible" << std::endl;
            break;
    }
}

