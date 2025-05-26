/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:27:29 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 16:55:14 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : m_type{""}
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : m_type{type}
{
    std::cout << "AMateria string constructor called" << std::endl;
}

AMateria::AMateria(const AMateria&)
{
    std::cout << "Copying the type of a Materia does not make sense" << std::endl;
}

void   AMateria::operator=(const AMateria&)
{
    std::cout << "Copying the type of a Materia does not make sense" << std::endl;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const& AMateria::getType(void) const
{
    return (m_type);
}

void    AMateria::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
