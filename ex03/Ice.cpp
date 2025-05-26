/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:27:01 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 13:59:39 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria{"ice"}
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria{other}
{
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice&    Ice::operator=(const Ice& ro)
{
    if (this == &ro)
        return (*this);
    AMateria::operator=(ro);
    std::cout << "Ice assignment constructor called";
    return (*this);
}

Ice::~Ice(void)
{
    std::cout << "Ice destructor called" << std::endl;
}

AMateria*   Ice::clone(void) const
{
    return (new Ice());
}

void    Ice::use(ICharacter& target)
{
    std::cout << "Ice: * shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}
