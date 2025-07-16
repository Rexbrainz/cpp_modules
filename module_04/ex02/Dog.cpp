/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 07:25:49 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 08:27:19 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(), m_brain{new  Brain()}
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), m_brain{new Brain(*other.m_brain)}
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    delete m_brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog&    Dog::operator=(const Dog& ro)
{
    if (this == &ro)
        return (*this);
    Animal::operator=(ro);
    delete m_brain;
    m_brain = new Brain(*ro.m_brain);
    std::cout << "Dog assignment operator called" << std::endl;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "Wooh Wooh Wooh" << std::endl;
}
