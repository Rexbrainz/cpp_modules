/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_type.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:32:47 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/06 17:58:04 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool    isChar(const std::string& literal)
{
    if (literal.size() == 1 && !isdigit(literal[0]))
        return (true);
    else
        return (false);
}

bool    isInt(const std::string& literal)
{
    static const std::regex Ints(R"([+-]?\d+)");

    return (std::regex_match(literal, Ints));
}

bool    isSpecialFloat(const std::string& literal)
{
    static const std::regex specialFloats(R"([+-]?inff|nanf)");

    return (std::regex_match(literal, specialFloats));
}

bool    isSpecialDouble(const std::string& literal)
{ 
    static const std::regex specialDoubles(R"([+-]?inf|nan|NaN)");

    return (std::regex_match(literal, specialDoubles));
}

bool    isFloat(const std::string& literal)
{ 
    static const std::regex floats(R"([+-]?(?:\d+\.\d*|\.\d+)[fF])");

    return (std::regex_match(literal, floats));
}

bool isDouble(const std::string& literal)
{
    static const std::regex doubles(R"([+-]?(?:\d+\.\d*|\d+\.|\d+))");

    return (std::regex_match(literal, doubles));
}

Types   detectType(std::string& literal)
{
    if (isChar(literal))
        return (Types::Char);
    else if (isSpecialFloat(literal))
        return (Types::SpecialFloat);
    else if (isSpecialDouble(literal))
        return (Types::SpecialDouble);
    else if (isFloat(literal))
        return (Types::Float);
    else if (isDouble(literal))
        return (Types::Double);
    else if (isInt(literal))
        return (Types::Int);
    else
        return (Types::None);
}


