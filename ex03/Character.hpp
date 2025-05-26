/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:28:29 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 17:51:08 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

const int   FLOOR_SIZE = 50;

struct  Character : ICharacter
{
    Character(void);
    Character(const std::string&);
    Character(const Character&);
    Character&  operator=(const Character&);
    ~Character(void);
    std::string const&  getName() const;
    void                equip(AMateria* m);
    void                unequip(int idx);
    void                use(int idx, ICharacter& target);
    void                addToFloor(AMateria*);
  private:
    std::string     m_name;
    AMateria*       m_inventory[SIZE];
    unsigned int    m_slots = 0;
    AMateria*       m_floor[FLOOR_SIZE];
    unsigned int    m_floor_index = 0;
};

#endif
