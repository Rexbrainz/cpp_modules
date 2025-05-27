/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:01:41 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/27 12:18:31 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : m_name{""}, m_slots{0}
{
    for (size_t i = 0; i < SIZE; i++)
        m_inventory[i] = nullptr;
}

Character::Character(const std::string& name) : m_name{name}, m_slots{0}
{
    for (size_t i = 0; i < SIZE; i++)
        m_inventory[i] = nullptr;
}

Character::Character(const Character& other)
    : m_name{other.m_name}, m_slots{other.m_slots}
{
    m_name = other.m_name;
    m_slots = other.m_slots;
    for (size_t i = 0; i < m_slots; i++)
        m_inventory[i] = other.m_inventory[i]->clone();
}

Character&  Character::operator=(const Character& ro)
{
    if (this == &ro)
        return (*this);
    m_name = ro.m_name;
    for (size_t i = 0; i < m_slots; i++)
        delete m_inventory[i];
    m_slots = ro.m_slots;
    for (size_t i = 0; i < m_slots; i++)
        m_inventory[i] = ro.m_inventory[i]->clone();
    return (*this);
}

std::string const&  Character::getName(void) const
{
    return (m_name);
}

void    Character::equip(AMateria* m)
{
   if (m_slots >= SIZE)
    {
        Floor::getFloor().dropMateria(m);
        return ;
    }
    m_inventory[m_slots++] = m;
}

void    Character::unequip(int idx)
{
    if (idx >= static_cast<int>(m_slots) || idx < 0)
        return ;
    Floor::getFloor().dropMateria(m_inventory[idx]);
    while (idx + 1 < static_cast<int>(m_slots))
    {
        m_inventory[idx] = m_inventory[idx + 1];
        idx++;
    }
    m_inventory[m_slots - 1] = nullptr;
    m_slots--;
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx >= static_cast<int>(m_slots) || idx < 0)
        return ;
    m_inventory[idx]->use(target);
}

Character::~Character(void)
{
    for (size_t i = 0; i < m_slots; i++)
        delete m_inventory[i];
}
