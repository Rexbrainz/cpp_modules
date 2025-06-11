/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:54:58 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/11 18:04:22 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

struct  Span
{
    Span() = delete;
    Span(unsigned int);
    Span(const Span&);
    Span(Span&&) noexcept;
    ~Span();

    using size_type = std::vector<int>::size_type;
    Span&   operator=(const Span&);
    Span&   operator=(Span&&) noexcept;

    void    swap(Span&) noexcept;

    void    addNumber(int);
    void    addMultipleNumbers(std::vector<int>::iterator,
                               std::vector<int>::iterator);
    void    verifyIndex();
    int     shortestSpan();
    int     longestSpan();
    void    isSpan();
  private:
    size_type           m_index{0};
    size_type           m_size{0};
    std::vector<int>    m_ivec;
};

void    swap(Span&, Span&) noexcept;

#endif
