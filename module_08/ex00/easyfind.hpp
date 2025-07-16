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
#include <algorithm>
#include <vector>

template<typename T>
int easyfind(T c, int target)
{
    auto f = std::find(c.begin(), c.end(), target);
    if (f != c.end())
        return (f - c.begin());
    else
        return (-1);
}

#endif
