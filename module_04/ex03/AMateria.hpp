/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:13:39 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 16:30:23 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

struct ICharacter;

const int SIZE = 4;

struct  AMateria
{
    AMateria(std::string const& type);
    virtual ~AMateria(void);

    std::string const&  getType(void) const;
    virtual AMateria*    clone(void) const = 0;
    virtual void        use(ICharacter& target);
  protected:
    AMateria(void);
    AMateria(const AMateria&);
    void   operator=(const AMateria&);
    std::string m_type;
};

#endif
