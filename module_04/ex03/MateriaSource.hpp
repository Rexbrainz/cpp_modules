/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:26:27 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/27 12:13:54 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include "Floor.hpp"

struct  MateriaSource : IMateriaSource
{
    MateriaSource(void);
    MateriaSource(const MateriaSource&);
    MateriaSource&  operator=(const MateriaSource&);
    ~MateriaSource(void);
    void            learnMateria(AMateria*);
    AMateria*       createMateria(std::string const& type);
  private:
    AMateria*       m_tempBuffer[SIZE];
    unsigned int    m_index;
    unsigned int    m_learnedMateria;
};

#endif


