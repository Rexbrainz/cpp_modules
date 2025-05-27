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

AMateria::AMateria(void) : m_type{""} {}

AMateria::AMateria(std::string const& type) : m_type{type} {}

AMateria::AMateria(const AMateria&) {}

void   AMateria::operator=(const AMateria&) {}

AMateria::~AMateria(void) {}

std::string const& AMateria::getType(void) const
{
    return (m_type);
}

void    AMateria::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
