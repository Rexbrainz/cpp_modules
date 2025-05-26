/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:00:24 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 16:37:27 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    m_index = other.m_index;
    for (size_t i = 0; i < m_index; i++)
        m_tempBuffer[i] = other.m_tempBuffer[i];
}

MateriaSource&    MateriaSource::operator=(const MateriaSource& ro)
{
    if (this == &ro)
        return (*this);
    for (size_t i = 0; i < m_index; i++)
        delete m_tempBuffer[i];
    m_index = ro.m_index;
    for (size_t i = 0; i < m_index; i++)
        m_tempBuffer[i] = ro.m_tempBuffer[i];
    return (*this);
}

void    MateriaSource::learnMateria(AMateria* copy)
{
    m_tempBuffer[m_index++ % SIZE] = copy;
}

AMateria*   MateriaSource::createMateria(std::string const& type)
{
    for (size_t i = 0; i < (m_index % SIZE); i++)
        if (type == m_tempBuffer[i]->getType())
            return (m_tempBuffer[i]->clone());
    return (0);
}

MateriaSource::~MateriaSource(void)
{
    for (size_t i = 0; i < (m_index % SIZE); i++)
        delete m_tempBuffer[i];
}
