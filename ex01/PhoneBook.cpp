/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:09:19 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/08 17:13:28 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add_contact(void)
{
	Contact	c;

	c.get_contact_fields();
	contacts[index % SIZE] = c;
	index++;
	if (index <= SIZE)
		contacts_saved++;
}

void	display_header(void)
{
	std::string	line_separator;
	
	line_separator = "+----------+----------+----------+----------+";
	std::cout << line_separator << std::endl;
	std::cout << "|" << std::setw(5/2 + 5) << "index";
   	std::cout << std::setw(10 - 5/2 - 5) << "";
	std::cout << "|" << std::setw(10) << "first name";
	std::cout << "|" << std::setw(10) << "last name";
	std::cout << "|" << std::setw(1 + 8) << "nickname";
	std::cout << std::setw(10 - 1 - 8) << "";
	std::cout << "|" << std::endl;	
	std::cout << line_separator << std::endl;
}

void PhoneBook::search(void)
{
	size_t		d_index;
	std::string	s_index;
	std::string	separator;

	separator =  "+----------+----------+----------+----------+";
	if (!contacts_saved)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	display_header();
	for (size_t i = 0; i < contacts_saved; i++)
	{
		contacts[i].summary_display(i);
		std::cout << separator << std::endl;
	}
	while (true)
	{
		std::cout << "Enter index to display: ";
		std::cin >> d_index;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input" << std::endl;
				continue ;
		}
		std::getline(std::cin, s_index); //To clear the newline character.
		if (d_index < contacts_saved)
			break ;
		std::cout << "Index entered is either wrong" << std::endl;
		std::cout << " or out of range" << std::endl;
	}
	contacts[d_index].display();
}
