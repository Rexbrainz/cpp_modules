/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 07:15:03 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/22 09:34:08 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << "\n--- Testing ClapTrap ---\n" << std::endl;

    ClapTrap c1("CL4P-TP");
    ClapTrap c2 = c1; // Copy constructor
    ClapTrap c3;
    c3 = c1; // Assignment operator

    c1.attack("Target A");
    c1.takeDamage(3);
    c1.beRepaired(5);
    c1.takeDamage(15); // To test hitPoints falling to 0
    c1.attack("Target B"); // Should not work due to 0 hitPoints

    std::cout << "\n--- Testing ScavTrap ---\n" << std::endl;

    ScavTrap s1("SC4V-TP");
    ScavTrap s2 = s1; // Copy constructor
    ScavTrap s3;
    s3 = s1; // Assignment operator

    s1.attack("Bandit");
    s1.takeDamage(25);
    s1.beRepaired(10);

    std::cout << "\n--- Testing energy depletion for scavtrap ---\n" << std::endl;
    // Test energy depletion
    for (int i = 0; i < 10; ++i)
        s1.attack("Training Dummy");

    s1.beRepaired(5); // Should fail due to 0 energy

    return 0;
}

