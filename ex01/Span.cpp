/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:04:18 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/11 18:09:24 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : m_size(N), m_ivec(N) {}

Span::Span(const Span& other) 
    : m_index{other.m_index}, m_size(other.m_size)
    , m_ivec(other.m_ivec)
{}

Span::Span(Span&& rhs) noexcept
{
    swap(rhs);
}

Span::~Span() {}

Span&   Span::operator=(const Span& rhs)
{
    Span    temp(rhs);

    swap(temp);
    return (*this);
}

Span&   Span::operator=(Span&& rhs) noexcept
{
    auto    temp{std::move(rhs)};

    swap(temp);
    return (*this);
}

void    Span::swap(Span& other) noexcept
{
    std::swap(m_size, other.m_size);
    std::swap(m_index, other.m_index);
    std::swap(m_ivec, other.m_ivec);
}

void    swap(Span& first, Span& second) noexcept
{
    first.swap(second);
}

void    Span::addNumber(int value)
{
    verifyIndex();
    m_ivec[m_index++] = value;
}

void    Span::addMultipleNumbers(std::vector<int>::iterator begin,
                                 std::vector<int>::iterator end)
{
    if (static_cast<size_type>(end - begin - 1) >= m_size)
        throw std::out_of_range("Error: Range size too large");
    for (; begin != end; ++begin)
        m_ivec[m_index++] = *begin;
}

void    Span::verifyIndex()
{
    if (m_index >= m_size)
        throw std::out_of_range("Error: Container out of space");
}

int Span::shortestSpan()
{
    isSpan();
    
    int minValue = std::numeric_limits<int>::max();
    std::sort(m_ivec.begin(), m_ivec.end());

    for (size_t i = 1; i < m_size; ++i)
        minValue = std::min(minValue, m_ivec[i] - m_ivec[i - 1]);
    return (minValue);
}

int Span::longestSpan()
{
    isSpan();
    auto    minMax = std::minmax_element(m_ivec.begin(), m_ivec.end());
    return (*minMax.second - *minMax.first);
}

void    Span::isSpan()
{
    if (m_index <= 1)
        throw std::out_of_range("Error: Span not found.");
}

