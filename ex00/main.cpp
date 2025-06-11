/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:16:50 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/10 10:20:12 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 7, 0, 5};
    int index = easyfind(ivec, 6);
    if (index >= 0)
        std::cout << ivec[index] << std::endl;
    else
        std::cout << "target not found" << std::endl;
    return (0);
}
