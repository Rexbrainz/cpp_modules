/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 08:28:45 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/10 16:41:19 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	horde;

	horde = zombieHorde(5, "Heap Zombie");
	for (int i = 0; i < 5; i++)
		horde[i].announce();	
	delete []horde;
	return (0);
}
