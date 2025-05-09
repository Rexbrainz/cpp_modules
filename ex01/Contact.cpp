/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:13:46 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/09 08:18:01 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool	is_phone_number_valid(std::string input)
{
	std::string::const_iterator	beg;

	beg = input.cbegin();
	if (*beg != '+' && !isdigit(*beg))
		return (false);
	beg++;
	for (; beg != input.cend(); beg++)
		if (!isdigit(*beg))
			return (false);
	return (true);
}

void	Contact::get_contact_fields(void)
{
	std::string	input;
	std::string	prompt_fields[5] = {"First name", "Last name", "Nick name",
									"Phone number", "Darkest secret"};
	for (size_t i = 0; i < 5; i++)
	{
		while (true)
		{
			std::cout << "Enter " << prompt_fields[i] << ": ";
			std::getline(std::cin, input);
			if (std::cin.eof())
			{
				std::cout << "\n\033[31mEof detected\033[0m" << std::endl;
				exit(1);
			}
			if (!input.empty())
			{
				if (prompt_fields[i] == "Phone number")
				{
					if (!is_phone_number_valid(input))
					{
						std::cout << "\033[31mError: invalid phone number\033[0m" << std::endl;
						std::cout << "\033[32mEnter a valid phone number\033[0m" << std::endl;
						continue ;
					}
				}
				contact_fields[i] = input;
				break ;
			}
			std::cout << "\033[31mContact fields cannot be empty\033[0m" << std::endl;
		}
	}
}

void	Contact::display(void)
{
	std::string	fields[5] = {"First name: ", "Last name: ", "Nickname: ",
								"Phone number: ", "Darkest secret: "};
	for (size_t i = 0; i < 5; i++)
		std::cout << fields[i] << contact_fields[i] << std::endl;
}

void	Contact::summary_display(size_t	index)
{
	std::string	temp[3];

	for (size_t i = 0; i < 3; i++)
	{
		temp[i] = contact_fields[i];
		if (temp[i].size() > 10)
			temp[i] = temp[i].substr(0, 9) + ".";
	}
	std::cout << "|" << std::setw(10) << index << "|";
	for (size_t i = 0; i < 3; i++)
		std::cout << std::setw(10) << temp[i] << "|";
	std::cout << std::endl;
}
