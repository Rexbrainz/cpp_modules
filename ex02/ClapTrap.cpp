/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:04:57 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/22 12:19:02 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("")
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string n) : name(n)
{
    std::cout << "ClapTrap String taking constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& ro)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this == &ro)
        return (*this);
    name = ro.name;
    hitPoints = ro.hitPoints;
    energyPoints = ro.energyPoints;
    attackDamage = ro.attackDamage;
    return (*this);
}

void    ClapTrap::attack(const std::string& target)
{
    if (energyPoints == 0 || hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points"
                  << " or no energy and cannot attack" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " attacks "
              << target << ", causing " << attackDamage
              << " points of damage!" << std::endl;
    energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints < amount)
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << "ClapTrap " << name << " Took a hit"
              << " and has " << hitPoints << " hitPoints left." 
              << std::endl;

}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints == 0 || hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points"
                  << " or hit points and cannot be repaired" << std::endl;
        return ;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " repairs itself and gains "
              << amount << " hitPoints" << std::endl;
}

