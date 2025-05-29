/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:47:57 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/29 16:59:42 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : m_name{DEFAULT_NAME}, m_grade{DEFAULT_GRADE} {}

Bureaucrat::Bureaucrat(const std::string& name, int grade = DEFAULT_GRADE)
    : m_name{name}
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    m_grade = grade;
}

Bureaucrat::~Bureaucrat(void) {}

std::string Bureaucrat::getName(void) const
{
    return (m_name);
}

unsigned int Bureaucrat::getGrade(void) const
{
    return (m_grade);
}

void    Bureaucrat::incrementGrade(void)
{
    if (m_grade - 1 < 1)
        throw GradeTooHighException();
    ++m_grade;
}

void    Bureaucrat::decrementGrade(void)
{
    if (m_grade + 1 > 150)
        throw GradeTooLowException();
    ++m_grade;
}

std::ostream&   operator<<(std::ostream& os, Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " 
        << b.getGrade();
    return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}
Bureaucrat::GradeTooHighException::GradeTooHighException(const char* exceptionMsg)
    :   m_msg{exceptionMsg} {}
const char* Bureaucrat::GradeTooHighException::getMsg(void) const
{
    return (m_msg);
}
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const char* exceptionMsg)
    :   m_msg{exceptionMsg} {}
const char* Bureaucrat::GradeTooLowException::getMsg(void) const
{
    return (m_msg);
}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) {}
