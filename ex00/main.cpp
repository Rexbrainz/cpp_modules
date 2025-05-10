/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 08:28:45 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/10 13:47:26 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	z;

	z = newZombie("Heap Zombie");
	z->announce();
	randomChump("Stack Zombie");	
	delete z;
	return (0);
}
