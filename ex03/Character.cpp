/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:01:41 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 17:51:12 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : m_name{""} {}

Character::Character(const std::string& name) : m_name{name} {}

Character::Character(const Character& other)
{
    m_name = other.m_name;
    m_slots = other.m_slots;
    for (size_t i = 0; i < m_slots; i++)
        m_inventory[i] = other.m_inventory[i];
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
        m_inventory[i] = ro.m_inventory[i];
    return (*this);
}

std::string const&  Character::getName(void) const
{
    return (m_name);
}

void    Character::equip(AMateria* m)
{
   if (m_slots >= SIZE)
        return ;
    m_inventory[m_slots++] = m;
}

void    Character::unequip(int idx)
{
    if (idx >= m_slots || idx < 0)
        return ;
    addToFloor(m_inventory[idx]);
    while (idx + 1 < SIZE)
    {
        m_inventory[idx] = m_inventory[idx + 1];
        idx++;
    }
    m_slots--;
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx >= m_slots || idx < 0)
        return ;
    m_inventory[idx]->use(target);
}

void    Character::addToFloor(AMateria* ptr)
{
    if (m_floor_index >= FLOOR_SIZE)
    {
        FLOOR_SIZE *= 2;
        AMateria*   temp = new AMateria[FLOOR_SIZE]; 
    }
}

Character::~Character(void)
{
    for (size_t i = 0; i < m_slots; i++)
        delete m_inventory[i];
}
