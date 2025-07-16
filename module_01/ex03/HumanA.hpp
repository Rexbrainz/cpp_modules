/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 07:04:42 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/12 08:44:25 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANA_HPP
#define	HUMANA_HPP

#include "Weapon.hpp"

struct HumanA
{
	HumanA(const std::string& hName, Weapon& weapon);
	void	attack(void);
 private:
	Weapon&		w;
	std::string	name;
};

#endif
