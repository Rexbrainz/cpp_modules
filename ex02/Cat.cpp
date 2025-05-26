/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 07:53:44 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 08:27:11 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(), m_brain{new Brain()}
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), m_brain{new Brain(*other.m_brain)}
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
    delete m_brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat&    Cat::operator=(const Cat& ro)
{
    if (this == &ro)
        return (*this);
    Animal::operator=(ro);
    delete m_brain;
    m_brain = new Brain(*ro.m_brain);
    std::cout << "Cat assignment operator called" << std::endl;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow Meow Meow" << std::endl;
}
