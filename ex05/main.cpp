/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 07:56:20 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/13 08:33:38 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;
	std::string	level;

	std::cout << "\033[32mHARL LOVES TO COMPLAIN\n"
			  << "Here are complain levels: "
			  << "DEBUG, INFO, WARNING or ERROR\033[0m\n"
			  << "\033[33mEnter any of the above complain levels: \033[0m";

	std::getline(std::cin, level);
	if (std::cin.eof())
	{
		std::cout << "\033[31mEof detected, exiting...\033[0m" << std::endl;
		return (0);
	}
	harl.complain(level);
	return (0);
}
