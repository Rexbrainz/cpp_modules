/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 07:24:34 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/12 08:48:24 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& hName, Weapon& weapon)
	: w(weapon), name(hName) {}


void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << w.getType() << std::endl;
}
