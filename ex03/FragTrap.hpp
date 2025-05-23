/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:23:40 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/22 11:29:14 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

struct FragTrap : public virtual ClapTrap
{
    FragTrap(void);
    FragTrap(std::string);
    FragTrap(const FragTrap&);
    ~FragTrap(void);
    FragTrap&   operator=(const FragTrap&);
    void        highFivesGuys(void);
};

#endif
