/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 07:44:50 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/12 09:05:24 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANB_HPP
#define	HUMANB_HPP

#include "Weapon.hpp"

struct HumanB
{
	HumanB(const std::string& hName);
	void	attack(void);
	void	setWeapon(Weapon& weapon);
 private:
	Weapon*		w = nullptr;
	std::string	name;
};

#endif
