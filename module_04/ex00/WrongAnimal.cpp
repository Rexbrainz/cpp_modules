/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:36:38 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/24 12:01:56 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal&    WrongAnimal::operator=(const WrongAnimal& ro)
{
    if (this == &ro)
        return (*this);
    type = ro.type;
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return (*this);
}

const std::string&  WrongAnimal::getType(void) const
{
    return (type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "???" << std::endl;
}
