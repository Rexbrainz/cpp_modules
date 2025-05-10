/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 07:49:37 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/10 09:31:30 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
#define	ZOMBIE_HPP

#include <iostream>
#include <string>

struct Zombie
{
	Zombie() = default;
	Zombie(const std::string& newName);
	~Zombie();
	void	announce(void);

  private:
	std::string	name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
