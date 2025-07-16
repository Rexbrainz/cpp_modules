/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 06:33:21 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/27 08:51:37 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "Character.hpp"


struct Floor
{
    Floor(void);
    Floor(const Floor&);
    Floor&  operator=(const Floor&);
    ~Floor(void);
    void    dropMateria(AMateria*);
    static Floor&   getFloor(void);
  private:
    AMateria**      m_floor;
    unsigned int    m_size;
    unsigned int    m_index;
    void            resize(void);
};

#endif
