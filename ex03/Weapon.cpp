/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 07:00:27 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/12 07:35:40 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string&	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(const std::string& weapon_type)
{
	type = weapon_type;
}

Weapon::Weapon(const std::string& weapon_type)
{
	type = weapon_type;
}
