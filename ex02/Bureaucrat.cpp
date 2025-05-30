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

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : m_name{name}
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
    : m_name{other.m_name}, m_grade{other.m_grade} {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
        m_grade = rhs.m_grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

const std::string& Bureaucrat::getName(void) const
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
        throw GradeTooHighException("Grade too high: out of range");
    --m_grade;
}

void    Bureaucrat::decrementGrade(void)
{
    if (m_grade + 1 > 150)
        throw GradeTooLowException();
    ++m_grade;
}

void    Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << m_name << " signed " << f.getName() << std::endl;
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cout << m_name << " couldn't sign " << f.getName()
                  << " because " << e.what() << std::endl;
    }

}

std::ostream&   operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " 
        << b.getGrade();
    return (os);
}

//GradeTooHighException Implementation

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
    : range_error{"Bureaucrat: Grade too High"} {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char* e)
    :   range_error{e} {}

//GradeTooLowException Implementation
Bureaucrat::GradeTooLowException::GradeTooLowException(void)
    : range_error{"Bureaucrat: Grade too Low"} {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char* e)
    :   range_error{e} {}

