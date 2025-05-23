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
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
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
    if (getEnergyPoints() == 0 || getHitPoints() == 0)
    {
        std::cout << "ScavTrap " << getName() << " has no hit points"
                  << " or no energy and cannot attack" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << getName() << " attacks "
              << target << ", causing " << getAttackDamage()
              << " points of damage!" << std::endl;
    auto    energy = getEnergyPoints();
    setEnergyPoints(--energy);
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
