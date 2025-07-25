/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 09:48:26 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/28 16:16:03 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <exception>
#include <map>
#include <vector>
#include <string>
#include <string_view>
#include <cctype>
#include <ctime>

struct  BitcoinExchange final
{
    BitcoinExchange() = delete;
    BitcoinExchange(std::string_view);
    ~BitcoinExchange() = default;
    BitcoinExchange(const BitcoinExchange&) = delete;
    BitcoinExchange&    operator=(const BitcoinExchange&) = delete;
    const std::map<std::string, float>&   getData() const;
    void    processFile(std::string_view) const;
  private:
    std::map<std::string, float>    m_data;
    void    processLine(const std::string&) const;
    bool    isDateValid(const std::string&) const;
    bool    verifyDateFields(const std::string&) const;
    float   validateValue(const std::string&) const;
    std::pair<std::string, float>  split(const std::string&, 
                                         const std::string&, bool) const;
};

#endif
