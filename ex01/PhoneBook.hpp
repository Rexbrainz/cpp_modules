/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:06:02 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/08 10:27:00 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

constexpr int SIZE = 8;

struct PhoneBook 
{
	void add_contact(void);
	void search(void);

  private:
	Contact	contacts[SIZE];
   	size_t	index = 0;
	size_t	contacts_saved = 0;
};

#endif
