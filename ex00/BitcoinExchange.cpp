/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:26:25 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/28 18:48:14 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string_view   data)
{
    std::string     line;
    std::ifstream   file(data);

    if (!file)
    {
        throw   std::runtime_error("data.csv cannot be opened.");
        exit(EXIT_FAILURE);
    }

    std::getline(file, line); //Skip file header

    while (std::getline(file, line))
    {
        // It is assumed that data.csv is correctly formatted
        // and therefore, split is expected not to throw.
        auto [date, price] { split(line, ",", true) };
        m_data.emplace(std::move(date), price);
    }
}

std::pair<std::string, float> 
BitcoinExchange::split(const std::string& line, 
                       const std::string& part, bool dataCsvFile) const
{
    std::string date;
    float       price;
    std::string strPrice;

    size_t      pos { line.find(part) };
    if (pos == std::string::npos)
        throw std::runtime_error("bad input => " + line);
    date = line.substr(0, pos);
    if (!dataCsvFile)
        if (!isDateValid(date))
            throw std::runtime_error("bad input => " + line);
    strPrice = line.substr(pos + part.size());
    if (!dataCsvFile)
        price = validateValue(strPrice);
    else
        price = stof(strPrice);
    return { date, price };
}

bool    BitcoinExchange::isDateValid(const std::string& date) const
{
    if (date.empty() || date.size() > 10)
        return (false);
    size_t  i = 0;
    while (i < 4)
        if (!isdigit(date[i++]))
            return (false);
    if (date[i++] != '-')
        return (false);
    while (i < 7)
        if (!isdigit(date[i++]))
            return (false);
    if (date[i++] != '-')
        return (false);
     while (i < 10)
        if (!isdigit(date[i++]))
            return (false);
    if (!verifyDateFields(date))
        return (false);
    return (true);
}

bool    BitcoinExchange::verifyDateFields(const std::string& date) const
{
    struct tm   t{};
    int year, month, day;
    char dash1, dash2;

    std::istringstream  iss(date);
    iss >> year >> dash1 >> month >> dash2 >> day;
    if (dash1 != '-' || dash2 != '-')
        return (false);
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    std::mktime(&t);
    return (t.tm_year == year - 1900 && 
            t.tm_mon == month - 1 &&
            t.tm_mday == day);
}

float    BitcoinExchange::validateValue(const std::string& strPrice) const
{
    try
    {
        if (strPrice.empty() || std::isspace(strPrice[0]))
            throw std::runtime_error("bad input => " + strPrice);
        size_t  pos { 0 };
        float   price { stof(strPrice, &pos) };
        if (pos != strPrice.size())
            throw std::runtime_error("bad input => " + strPrice);
        if (price > 1000)
            throw std::runtime_error("too large a number.");
        else if (price < 0)
            throw std::runtime_error("not a positive number.");
        return (price);
    }
    catch (const std::out_of_range&)
    {
        throw std::runtime_error("value is out of range.");
    }
    catch (const std::invalid_argument&)
    {
        throw std::runtime_error("value is not an int nor float.");
    }
}

void    BitcoinExchange::processFile(std::string_view input) const
{
    std::ifstream   file(input);

    if (!file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;

    if (!std::getline(file, line))
    {
        std::cerr << "Error: File is empty." << std::endl;
        exit(EXIT_FAILURE);
    }
   
    if (line == "date | value")
        ;
    else
        processLine(line);
    while (std::getline(file, line))
        processLine(line);
}

void    BitcoinExchange::processLine(const std::string& line) const
{
    try
    {
        auto [date, value] { split(line, " | ", false) };
        auto it { m_data.lower_bound(date) };
        if (it == end(m_data))
            --it ;
        else if (it->first != date && it != begin(m_data))
            --it ;
        else if (it->first != date && it == begin(m_data))
        {
            std::cout << "Date not found and there is no previous date."
                    << std::endl;
            return ;
        }
        std::cout << it->first << " => " << value << " = "
                    << value * it->second << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

