/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:24:37 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/23 08:48:08 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap() 
{
    name = "";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string n) : 
    ClapTrap(n + "_clap_name"), FragTrap(n), ScavTrap(n)
{
    name = n;
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap string constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : 
    ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& ro)
{
    if (this == &ro)
        return (*this);
    ClapTrap::operator=(ro);
    name = ro.name;
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    return (*this);
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "I am " << ClapTrap::name << " (" << name
              << "). You aint reaaaady for me!" << std::endl;
}

