/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 07:25:49 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/24 08:45:53 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog&    Dog::operator=(const Dog& ro)
{
    if (this == &ro)
        return (*this);
    Animal::operator=(ro);
    std::cout << "Dog assignment operator called" << std::endl;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "Wooh Wooh Wooh" << std::endl;
}
