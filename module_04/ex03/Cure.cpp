/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:53:54 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/27 12:24:37 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria{"cure"} {}

Cure::Cure(const Cure& other) : AMateria{other} {}

Cure&   Cure::operator=(const Cure& ro)
{
    if (this == &ro)
        return (*this);
    AMateria::operator=(ro);
    return (*this);
}

AMateria*   Cure::clone(void) const
{
    return (new Cure());
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *"
              << std::endl;
}

Cure::~Cure(void) {}
