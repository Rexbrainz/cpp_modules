/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 08:28:45 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/13 12:30:42 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	horde;

	horde = zombieHorde(SIZE, "Heap Zombie");
	if (horde)
	{
		for (int i = 0; i < SIZE; i++)
			horde[i].announce();
	}
	else
		std::cout << "No horde created" << std::endl;
	delete []horde;
	return (0);
}
