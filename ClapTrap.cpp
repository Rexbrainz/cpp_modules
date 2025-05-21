/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:04:57 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/21 15:05:02 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("")
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string n) : name(n)
{
    std::cout << "String taking constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor called" << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    hitPoints = other.energyPoints;
    attackDamage = other.attackDamage;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& ro)
{
    std::cout << "Copy assignment operator called" << std::endl;
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
    std::cout << "ClapTrap " << name << "attacks "
              << target << ", causing " << attackDamage
              << "points of damage!";
    energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << name << "repairs it self and gains "
              << amount << "of hit points" << std::endl;
    if (amount > 10)
        amount = 10;
    else if (amount < 0)
        amount = 0;
    hitPoints = amount;
    energyPoints--;
}

