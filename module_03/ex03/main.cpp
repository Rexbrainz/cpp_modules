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

#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap dt("Success");

    std::cout << "\n=== Identity Check ===" << std::endl;
    dt.whoAmI();

    std::cout << "\n=== Attacking ===" << std::endl;
    dt.attack("target");

    std::cout << "\n=== Copy and Assignment ===" << std::endl;
    DiamondTrap copy(dt);
    copy.whoAmI();

    DiamondTrap assigned;
    assigned = dt;
    assigned.whoAmI();

    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}

