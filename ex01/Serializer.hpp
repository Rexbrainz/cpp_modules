/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:10:55 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/07 14:34:06 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

struct  Data
{
    int m_i = 42;
    float m_f = 42.0f;
    double m_d = 42.00;
    std::string m_s = "Forty two";
};


struct  Serializer
{
    Serializer() = delete;
    ~Serializer() = delete;
    Serializer(const Serializer&) = delete;
    Serializer& operator=(const Serializer&) = delete;

    static uintptr_t    serialize(Data* ptr);
    static Data*        deserialize(uintptr_t raw);
};

#endif
