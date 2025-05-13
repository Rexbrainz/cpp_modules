/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:34:56 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/13 08:35:22 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl::PMF			complain[] = {&Harl::debug, &Harl::info,
	   						&Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*complain[i])();
			return ;
		}
	}
	std::cout << "Harl winks 😉: you did not get me this time."
		      << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "I really like my codes working properly. Not sure..." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I am not sure why the code does not work.\n";
	std::cout << "Looking at the code, it shows everything looks fine.\n";
	std::cout << "Could this be machine dependent?"
	   	      << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "If this doesn't work, i might just quit at this moment.";
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This code just does not work: I need help!!!" << std::endl;
	std::cout << "Just anyone, HELP PLEASE!!!" << std::endl;
}
