/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:26:27 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 16:28:11 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

struct  MateriaSource
{
    MateriaSource(void);
    MateriaSource(const MateriaSource&);
    MateriaSource&  operator=(const MateriaSource&);
    ~MateriaSource(void);
    void            learnMateria(AMateria*);
    AMateria*       createMateria(std::string const& type);
  private:
    AMateria*       m_tempBuffer[SIZE];
    unsigned int    m_index = 0;
};

#endif


