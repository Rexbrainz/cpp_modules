/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:50:54 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 14:00:08 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

struct Cure : AMateria
{
    Cure(void);
    Cure(const Cure&);
    Cure&       operator=(const Cure&);
    ~Cure(void);
    AMateria*   clone(void) const;
    void        use(ICharacter& target);
};

#endif
