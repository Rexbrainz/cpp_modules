/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:44:29 by sudaniel          #+#    #+#             */
/*   Updated: 2025/07/05 15:49:24 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <numeric>
#include <stack>
#include <string_view>
#include <cctype>

struct  RPN
{
    RPN() = default;
    RPN(const RPN&) = delete;
    RPN&    operator=(const RPN&) = delete;
    ~RPN() = default;
    int     calculate(std::string_view);

  private:
    std::stack<int> m_stack;
    int     pop();
    void    underflow();
    bool    isValidOperator(int ch);
    int     operations(int);
    void    isWithinIntRange(long long);
    int     verifyResult(int, int, char);
    std::pair<int, std::string_view::const_iterator>
            getValueAndUpdateIterator(std::string_view::const_iterator,
                     std::string_view::const_iterator);
};

#endif
