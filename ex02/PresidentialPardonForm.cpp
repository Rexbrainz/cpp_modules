/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:22:38 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/02 13:13:17 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& s) 
    :   AForm{"PresidentialPardonForm", false, 25, 5}, m_target{s}
{}

PresidentialPardonForm::
    PresidentialPardonForm(const PresidentialPardonForm& other)
    :  AForm{other}, m_target{other.m_target} 
{}

PresidentialPardonForm&
    PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        m_target = rhs.m_target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void    PresidentialPardonForm::execute(Bureaucrat const& e) const
{
    if (!getSign())
        throw GradeTooLowException("Execution failed: PresidentialPardonForm not signed");
    if (!verifyExecPermission(e))
        throw GradeTooLowException("Execution failed: Grade too low to execute pardon.");
    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

