/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 07:24:38 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/05 10:25:12 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	switch (argc)
	{
		case 1:
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
			break;
		default:
			while (*++argv)
			{
				std::string	str(*argv);
				for (auto &i : str)
				{
					i = toupper(i);
					std::cout << i;
				}
			}
			break;
	}
	std::cout << std::endl;
	return (0);
}

