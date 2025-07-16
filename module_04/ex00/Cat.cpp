/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 07:53:44 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/24 08:45:22 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat&    Cat::operator=(const Cat& ro)
{
    if (this == &ro)
        return (*this);
    Animal::operator=(ro);
    std::cout << "Cat assignment operator called" << std::endl;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow Meow Meow" << std::endl;
}
