/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:20:28 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 13:56:49 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

struct AMateria;

struct  ICharacter
{
    virtual ~ICharacter(void) {}
    virtual std::string const&  getName() const = 0;
    virtual void                equip(AMateria* m) = 0;
    virtual void                unequip(int idx) = 0;
    virtual void                use(int idx, ICharacter& target) = 0;
};

#endif
