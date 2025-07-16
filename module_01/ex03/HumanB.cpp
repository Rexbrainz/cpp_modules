/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 07:51:29 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/12 09:06:09 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& hName) : name(hName) {}

void	HumanB::setWeapon(Weapon& weapon)
{
	w = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their " << w->getType() << std::endl;
}

