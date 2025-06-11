/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:01:49 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/10 10:16:32 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

template<typename T>
int easyfind(T c, int target)
{
    for (auto b = c.begin(); b != c.end(); ++b)
        if (*b == target)
            return (b - c.begin());
    return (-1);
}

#endif
