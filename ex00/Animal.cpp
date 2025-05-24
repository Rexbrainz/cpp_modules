/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 07:12:05 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/24 08:40:03 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
    std::cout << "Animal default constructor created" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& ro)
{
    if (this == &ro)
        return (*this);
    type = ro.type;
    std::cout << "Animal copy assignment operator called" << std::endl;
    return (*this);
}

const std::string&    Animal::getType(void) const
{
    return (type);
}

void    Animal::makeSound(void) const
{
    std::cout << "What animal are you refering to?" << std::endl;
}
