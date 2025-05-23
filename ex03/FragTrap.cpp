/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:29:58 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/22 11:39:19 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap defaul constructor called" << std::endl;
}

FragTrap::FragTrap(std::string n) : ClapTrap(n)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap string constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& ro)
{
    if (this == &ro)
        return (*this);
    ClapTrap::operator=(ro);
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "Great!!! Give me high-fives guys!" << std::endl;
}
