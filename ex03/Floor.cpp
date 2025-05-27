/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 06:41:13 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/27 08:05:37 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor(void) : m_size{10}, m_index{0}
{
    m_floor = new AMateria*[m_size];
    for (size_t i = 0; i < m_size; i++)
        m_floor[i] = nullptr;
}

Floor::Floor(const Floor& other)
    : m_size{other.m_size}, m_index{other.m_index}
{
    m_floor = new AMateria*[m_size];
    for (size_t i = 0; i < m_size; i++)
    {
        if (other.m_floor[i])
            m_floor[i] = other.m_floor[i]->clone();
         else
            m_floor[i] = nullptr;
    }
}

Floor&    Floor::operator=(const Floor& ro)
{
    if (this != &ro)
    {
        for (size_t i = 0; i < m_index; i++)
            delete m_floor[i];
        delete[] m_floor;
        m_size = ro.m_size;
        m_index = ro.m_index;
        m_floor = new AMateria*[m_size];
        for (size_t i = 0; i < m_size; i++)
        {
            if (ro.m_floor[i])
                m_floor[i] = ro.m_floor[i]->clone();
             else
                m_floor[i] = nullptr;
        }
    }
    return (*this);
}

Floor&  Floor::getFloor(void)
{
    static Floor instance;

    return (instance);
}

void    Floor::dropMateria(AMateria* ptr)
{
    if (m_index == m_size)
        resize();
    m_floor[m_index++] = ptr;
}

void    Floor::resize(void)
{
    unsigned int    newSize;
    AMateria**      newFloor;

    newSize = m_size * 2;
    newFloor = new AMateria*[newSize];
    for (size_t i = 0; i < newSize; i++)
    {
        if (i < m_size)
            newFloor[i] = m_floor[i];
         else
            newFloor[i] = nullptr;
    }
    delete[] m_floor;
    m_floor = newFloor;
    m_size = newSize;
}

Floor::~Floor(void)
{
    for (size_t i = 0; i < m_index; i++)
        delete m_floor[i];
    delete[] m_floor;
}
