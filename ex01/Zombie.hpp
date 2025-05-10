/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 07:49:37 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/10 16:20:30 by sudaniel         ###   ########.fr       */
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
	void	setName(const std::string& newName);

  private:
	std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
