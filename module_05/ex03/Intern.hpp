/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:40:23 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/03 13:43:53 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const int   FORM_SIZE = 3;

struct  Intern
{
    Intern();
    Intern(const Intern&);
    Intern& operator=(const Intern&);
    ~Intern();
    using pFormCreators = AForm* (Intern::*)(const std::string&);
    AForm*  makeForm(const std::string&, const std::string&);
    int     searchFormNames(const std::string&);
    AForm*  createShrubberyCreationForm(const std::string&);
    AForm*  createRobotomyRequestForm(const std::string&);
    AForm*  createPresidentialPardonForm(const std::string&);
  private:
    std::string m_formNames[FORM_SIZE];
};

#endif


