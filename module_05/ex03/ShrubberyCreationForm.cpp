/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:04:03 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/03 14:34:15 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm{"ShrubberyCreationForm", false, 145, 137}, m_target{""}
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& s)
    : AForm{"ShrubberyCreationForm", false, 145, 137}, m_target{s}
{}

ShrubberyCreationForm::
    ShrubberyCreationForm(const ShrubberyCreationForm& other)
    :  AForm{other}, m_target{other.m_target}
{}

ShrubberyCreationForm&  
    ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        m_target = rhs.m_target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void    ShrubberyCreationForm::execute(Bureaucrat const& e) const
{
    if (!getSign())
        throw GradeTooLowException("Execution failed: Form not signed");
    if (!verifyExecPermission(e))
        throw GradeTooLowException("Execution Failed: Grade too Low");

    std::ofstream   out(m_target + "_shrewbbery");

    out << "   /\\\n"
        << "  /**\\\n"
        << " /****\\\n"
        << "/******\\\n"
        << "   ||\n"
        << "   ||\n"
        << std::endl;
    out.close();
}

