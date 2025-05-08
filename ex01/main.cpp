/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:45:48 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/08 17:00:14 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
  PhoneBook phonebook;
  std::string cmd;

  std::cout << "A crappy phonebook" << std::endl;
  std::cout << "To add a contact, enter ADD" << std::endl;
  std::cout << "To look up a contact, enter SEARCH" << std::endl;
  std::cout << "To exit the program, enter EXIT" << std::endl;

  while (true)
  {
	  std::cout << "Enter a command (ADD, SEARCH or EXIT): " << std::flush;
	  std::getline(std::cin, cmd);
	  if (cmd == "ADD")
		  phonebook.add_contact();
	  else if (cmd == "SEARCH")
		  phonebook.search();
	  else if (cmd == "EXIT")
		  break ;
  }
  return (0);
}
