/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:06:22 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/24 12:15:11 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&   WrongCat::operator=(const WrongCat& ro)
{
    if (this == &ro)
        return (*this);
    WrongAnimal::operator=(ro);
    std::cout << "WrongCat assignment operator called" << std::endl;
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << "WrongMeow Wromeow WrMeow" << std::endl;
}
