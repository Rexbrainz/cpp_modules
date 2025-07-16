/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:34:56 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/13 09:25:36 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int		Harl::mapLevels(std::string& level)
{
	if (level == "DEBUG")
		return (DEBUG);
	else if (level == "INFO")
		return (INFO);
	else if (level == "WARNING")
		return (WARNING);
	else if (level == "ERROR")
		return (ERROR);
	else
		return (DEFAULT);
}

void	Harl::complain(std::string level)
{
	Harl::PMF	complain[] = {&Harl::debug, &Harl::info,
	   						&Harl::warning, &Harl::error};

	switch(mapLevels(level))
	{
		case DEBUG:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*complain[DEBUG])();
			std::cout << std::endl;
		case INFO:
			std::cout << "[ INFO ]" << std::endl;
			(this->*complain[INFO])();
			std::cout << std::endl;
		case WARNING:
			std::cout << "[ WARNING ]" << std::endl;
			(this->*complain[WARNING])();
			std::cout << std::endl;
		case ERROR:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*complain[ERROR])();
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
			          << std::endl;
	}
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
