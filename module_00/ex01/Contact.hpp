/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:04:03 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/08 15:15:30 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>

struct Contact
{
   	void get_contact_fields();
	void display(void);
	void summary_display(size_t index);

  private:
	std::string	contact_fields[5];
};

#endif
