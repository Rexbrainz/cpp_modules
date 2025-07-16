/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 08:21:30 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/22 09:32:15 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "String constructor for ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& ro)
{
    if (this == &ro)
        return (*this);
    ClapTrap::operator=(ro);
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    return (*this);
}

void    ScavTrap::attack(const std::string& target)
{
    if (energyPoints == 0 || hitPoints == 0)
    {
        std::cout << "ScavTrap " << name << " has no hit points"
                  << " or no energy and cannot attack" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << name << " attacks "
              << target << ", causing " << attackDamage
              << " points of damage!" << std::endl;
    energyPoints--;
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
