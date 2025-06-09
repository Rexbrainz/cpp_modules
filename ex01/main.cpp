/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:36:53 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/09 09:52:43 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void    print(const T& c)
{
    std::cout << c << " ";
}

template<typename T>
void    doubleValue(T& value)
{
    value *= 2;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    void (*pfi)(int&) = doubleValue;
    void (*pfv)(const int&) = print;

    iter(arr, 7, pfv);
    std::cout << std::endl;
    iter(arr, 7, pfi);
    for (auto i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
    return (0);
}
