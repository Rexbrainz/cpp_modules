/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 06:53:57 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/12 08:19:36 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define	WEAPON_HPP

#include <iostream>
#include <string>

struct Weapon
{
	Weapon() = default;
	Weapon(const std::string& weapon_type);
	const std::string&	getType(void);
	void	setType(const std::string& weapon_type);
 private:
	 std::string	type;
};

#endif


