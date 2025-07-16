/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Function_templates.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 07:38:32 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/09 07:46:01 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_TEMPLATES_HPP
#define FUNCTION_TEMPLATES_HPP

#include <iostream>
#include <string>

template<typename T>
void    swap(T& a, T& b)
{
    T   tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T   min(const T& a, const T& b)
{
    return (a < b ? a : b);
}

template<typename T>
T   max(const T& a, const T& b)
{
    return (a > b ? a : b);
}

#endif
