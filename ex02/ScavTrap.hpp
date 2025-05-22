/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 08:29:28 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/22 09:32:23 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

struct ScavTrap : public ClapTrap
{
    ScavTrap(void);
    ScavTrap(std::string);
    ScavTrap(const ScavTrap&);
    ~ScavTrap(void);
    ScavTrap&   operator=(const ScavTrap&);
    void        guardGate(void);
};

#endif
