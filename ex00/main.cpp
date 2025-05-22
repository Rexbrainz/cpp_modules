/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 07:15:03 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/22 07:16:32 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot1("Trapster");
    ClapTrap bot2("Destructor");

    std::cout << "\n--- Starting test ---\n" << std::endl;

    // Set bot1's damage
    bot1.attack("Destructor"); // default attackDamage is 0
    bot1.takeDamage(5);        // should have 5 hitPoints left
    bot1.beRepaired(3);        // should go to 8 hitPoints

    // Deplete energy
    for (int i = 0; i < 10; ++i)
        bot1.attack("Destructor");

    bot1.attack("Destructor"); // Should print "no energy" message
    bot1.beRepaired(2);        // Should fail due to 0 energy

    // Kill bot2 and try to make it act
    bot2.takeDamage(10);       // Should drop to 0 hitPoints
    bot2.attack("Trapster");   // Should not work
    bot2.beRepaired(5);        // Should not work

    // Test copy constructor and assignment operator
    ClapTrap copyBot(bot1);    // Uses copy constructor
    ClapTrap assignBot;
    assignBot = bot2;          // Uses copy assignment

    std::cout << "\n--- Ending test ---" << std::endl;

    return 0;
}

