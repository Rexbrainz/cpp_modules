/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:15:16 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/23 08:24:02 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

struct  DiamondTrap : FragTrap, ScavTrap
{
    DiamondTrap(void);
    DiamondTrap(std::string);
    DiamondTrap(const DiamondTrap&);
    ~DiamondTrap(void);
    DiamondTrap&    operator=(const DiamondTrap&);
    void            attack(const std::string&) override;
    void            whoAmI(void);
  private:
    std::string     name;
};

#endif
