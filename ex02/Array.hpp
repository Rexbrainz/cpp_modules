/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:19:37 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/09 11:41:40 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template<typename T>
struct  Array
{
    Array();
    Array(unsigned int);
    ~Array();
    Array(const Array&);

    typedef typename std::size_t size_type;
    Array&          operator=(const Array&);
    T&              operator[](size_type);
    const T&        operator[](size_type) const;
    size_type       size() const;
    void            verifyIndex(size_type) const;
  private:
    size_type   m_size = 0;
    T*          m_array = nullptr;
};

#include "Array.tpp"

#endif
