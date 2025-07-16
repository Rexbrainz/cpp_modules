/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:45:48 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/09 08:32:29 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
  PhoneBook phonebook;
  std::string cmd;

  std::cout << "\n" << std::endl;
  std::cout << "\033[32mA crappy phonebook\033[0m" << std::endl;
  std::cout << "\033[32mTo add a contact, enter ADD\033[0m" << std::endl;
  std::cout << "\033[32mTo look up a contact, enter SEARCH\033[0m" << std::endl;
  std::cout << "\033[32mTo exit the program, enter EXIT\033[0m" << std::endl;
  std::cout << "\n" << std::endl;
  while (true)
  {
	  std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
	  std::getline(std::cin, cmd);
	  if (std::cin.eof())
	  {
	  	std::cout << "\n\033[31mEOF detected, exiting...\033[0m";
		std::cout << std::endl;
		return (1);
	  }
	  if (cmd == "ADD")
		  phonebook.add_contact();
	  else if (cmd == "SEARCH")
		  phonebook.search();
	  else if (cmd == "EXIT")
		  break ;
  }
  return (0);
}
