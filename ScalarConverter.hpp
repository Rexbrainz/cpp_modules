/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:05:16 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/06 17:59:55 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include <limits>

enum class  Types
{
    Char, 
    Int,
    Float,
    Double,
    SpecialFloat,
    SpecialDouble,
    None
};

struct  ScalarConverter
{
    ScalarConverter() = delete;
    ScalarConverter(const ScalarConverter&) = delete;
    ScalarConverter&    operator=(const ScalarConverter&) = delete;
    ~ScalarConverter() = delete;

    static void convert(std::string);
};


Types   detectType(std::string&);
bool    isChar(const std::string&);
bool    isInt(const std::string&);
bool    isSpecialFloat(const std::string&);
bool    isSpecialDouble(const std::string&);
bool    isFloat(const std::string&);
bool    isDouble(const std::string&);

//Ranges
bool isFloatWithinIntRange(float value);
bool isDoubleWithinIntRange(double value);
bool isDoubleWithinFloatRange(double value);

//Value getters
int getInt(std::string& literal);
float getFloat(std::string& literal);
double getDouble(std::string& literal);

//Converters
void    ConvertFromChar(std::string& literal);
void    ConvertFromInt(std::string& literal);
void    ConvertFromSpecialFloat(std::string& literal);
void    ConvertFromSpecialDouble(std::string& literal);
void    ConvertFromFloat(std::string& literal);
void    ConvertFromDouble(std::string& literal);

#endif
