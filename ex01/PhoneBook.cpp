/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:09:19 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/09 08:14:50 by sudaniel         ###   ########.fr       */
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
	int			d_index;
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
		std::getline(std::cin, s_index);
		if (std::cin.eof())
		{
			std::cout << "\033[31m\nEOF detected, exiting.\033[0m" << std::endl;
			exit(1);
		}
		try
		{
			d_index = std::stoi(s_index);
		}
		catch (std::invalid_argument &e)
		{
			std::cerr << "\033[31mInvalid argument\033[0m" << std::endl;
			continue ;
		}
		catch (std::out_of_range &e)
		{
			std::cerr << "\033[31mOut of range input\033[0m" << std::endl;
			continue ;
		}
		if (d_index < 0 || (size_t)d_index >= contacts_saved)
		{
			std::cout << "\033[31mIndex entered is either wrong\033[0m" << std::endl;
			std::cout << "\033[31m or out of range\033[0m" << std::endl;
		}
		else
			break;
	}
	contacts[d_index].display();
}
