/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:22:51 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 16:29:33 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIA_SOURCE_HPP
#define IMATERIA_SOURCE_HPP

#include "AMateria.hpp"

struct  IMateriaSource
{
    virtual ~IMateriaSource() {}
    virtual void        learnMateria(AMateria*) = 0;
    virtual AMateria*   createMateria(std::string const& type) = 0;
};

#endif
