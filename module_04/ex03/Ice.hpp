/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:22:17 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 13:59:46 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

struct  Ice : AMateria
{
    Ice(void);
    Ice(const Ice&);
    Ice&    operator=(const Ice&);
    ~Ice(void); 
    AMateria*   clone(void) const;
    void        use(ICharacter& target);
};

#endif
