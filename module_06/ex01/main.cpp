/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:28:29 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/07 14:49:46 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data    data;
    Data*   ptr;

    ptr = Serializer::deserialize(Serializer::serialize(&data));

    std::cout << ptr << std::endl;
    std::cout << &data << std::endl;
    return (0);
}
