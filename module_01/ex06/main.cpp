/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 07:56:20 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/13 08:51:11 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\033[31mError: Wrong argument count\n"
		   		  << "Program name and complain level\033[0m"
				  <<  std::endl;
		return (0);
	}
	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}
