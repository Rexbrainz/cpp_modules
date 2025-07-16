/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:27:01 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/27 12:22:38 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria{"ice"} {}

Ice::Ice(const Ice& other) : AMateria{other} {}

Ice&    Ice::operator=(const Ice& ro)
{
    if (this == &ro)
        return (*this);
    AMateria::operator=(ro);
    return (*this);
}

Ice::~Ice(void) {}

AMateria*   Ice::clone(void) const
{
    return (new Ice());
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}
