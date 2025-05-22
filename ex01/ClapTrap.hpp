/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:42:55 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/22 09:32:28 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <string>

struct ClapTrap
{
    ClapTrap(void);
    ClapTrap(std::string);
    ClapTrap(const ClapTrap&);
    ~ClapTrap(void);
    ClapTrap&       operator=(const ClapTrap&);
    void            attack(const std::string& target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);
  private:
    std::string     name;
    unsigned int    hitPoints = 100;
    unsigned int    energyPoints = 50;
    unsigned int    attackDamage = 20;
};

#endif
