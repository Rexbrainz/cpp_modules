/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 07:15:03 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/22 11:55:29 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "\n=== [CLAPTRAP TESTING] ===" << std::endl;
    ClapTrap clap("Clappy");

    clap.attack("enemy");
    clap.takeDamage(3);
    clap.beRepaired(5);
    clap.takeDamage(10);  // Should reduce to 0 HP
    clap.attack("enemy"); // Should fail due to 0 HP

    std::cout << "\n=== [SCAVTRAP TESTING] ===" << std::endl;
    ScavTrap scav("Scavy");

    scav.attack("intruder");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();         // Unique method
    scav.attack("intruder");  // Should fail
    scav.beRepaired(5);       // Should fail

    std::cout << "\n=== [FRAGTRAP TESTING] ===" << std::endl;
    FragTrap frag("Fraggy");

    frag.attack("target");
    frag.takeDamage(40);
    frag.beRepaired(30);
    frag.highFivesGuys();     // Unique method
    frag.attack("target");    // Should fail
    frag.beRepaired(10);      // Should fail

    std::cout << "\n=== [COPY & ASSIGNMENT TESTING] ===" << std::endl;
    ScavTrap scav2(scav);     // Copy constructor
    FragTrap frag2;
    frag2 = frag;             // Assignment

    std::cout << "\n=== [END OF MAIN] ===" << std::endl;
    return 0;
}

