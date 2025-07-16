/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:00:24 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/27 08:43:20 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : m_index{0}, m_learnedMateria{0}
{
    for (size_t i = 0; i < SIZE; i++)
        m_tempBuffer[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other)
    : m_index{other.m_index}, m_learnedMateria{other.m_learnedMateria}
{
    for (size_t i = 0; i < m_index; i++)
        m_tempBuffer[i] = other.m_tempBuffer[i]->clone();
}

MateriaSource&    MateriaSource::operator=(const MateriaSource& ro)
{
    if (this == &ro)
        return (*this);
    for (size_t i = 0; i < m_index; i++)
        delete m_tempBuffer[i];
    m_index = ro.m_index;
    m_learnedMateria = ro.m_learnedMateria;
    for (size_t i = 0; i < m_index; i++)
        m_tempBuffer[i] = ro.m_tempBuffer[i]->clone();
    return (*this);
}

void    MateriaSource::learnMateria(AMateria* copy)
{
    if (m_learnedMateria == SIZE && m_tempBuffer[m_index % SIZE])
        Floor::getFloor().dropMateria(m_tempBuffer[m_index % SIZE]);
    m_tempBuffer[m_index++ % SIZE] = copy;
    if (m_learnedMateria <= SIZE)
        m_learnedMateria++;
}

AMateria*   MateriaSource::createMateria(std::string const& type)
{
    for (size_t i = 0; i < m_learnedMateria; i++)
        if (type == m_tempBuffer[i]->getType())
            return (m_tempBuffer[i]->clone());
    return (0);
}

MateriaSource::~MateriaSource(void)
{
    for (size_t i = 0; i < m_learnedMateria; i++)
        delete m_tempBuffer[i];
}
