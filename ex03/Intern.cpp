/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:22:12 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/03 14:43:38 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    m_formNames[0] = "shrubbery creation";
    m_formNames[1] = "robotomy request";
    m_formNames[2] = "presidential pardon";
}

Intern::Intern(const Intern& other)
{
    m_formNames[0] = other.m_formNames[0];
    m_formNames[1] = other.m_formNames[1];
    m_formNames[2] = other.m_formNames[2];
}

Intern& Intern::operator=(const Intern& rhs)
{
    if (this != &rhs)
    {
        m_formNames[0] = rhs.m_formNames[0];
        m_formNames[1] = rhs.m_formNames[1];
        m_formNames[2] = rhs.m_formNames[2];
    }
    return (*this);
}

AForm*  
    Intern::makeForm(const std::string& formName, const std::string& target)
{
    int     index = 0;
    AForm*  form;

    pFormCreators   formFunctions[FORM_SIZE] =
        {
            &Intern::createShrubberyCreationForm,
            &Intern::createRobotomyRequestForm,
            &Intern::createPresidentialPardonForm
        };
    if ((index = searchFormNames(formName)) < 0)
    {
        std::cout << "Form name does not exist" << std::endl;
        return (nullptr);
    }
    form = (this->*formFunctions[index])(target);
    std::cout << "Intern creates " << *form << std::endl;
    return (form);
}

int     Intern::searchFormNames(const std::string& formNames)
{
    for (size_t i = 0; i < FORM_SIZE; i++)
        if (m_formNames[i] == formNames)
            return (i);
    return (-1);
}

AForm*
Intern::createShrubberyCreationForm(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm*  
Intern::createRobotomyRequestForm(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm*  
Intern::createPresidentialPardonForm(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

Intern::~Intern() {}


