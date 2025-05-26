/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:53:54 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 13:59:28 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria{"cure"}
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria{other}
{
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure&   Cure::operator=(const Cure& ro)
{
    if (this == &ro)
        return (*this);
    AMateria::operator=(ro);
    std::cout << "Cure Assignment operator called" << std::endl;
    return (*this);
}

AMateria*   Cure::clone(void) const
{
    return (new Cure());
}

void    Cure::use(ICharacter& target)
{
    std::cout << "Cure: * shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor called" << std::endl;
}
