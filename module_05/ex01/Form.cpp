/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:14:04 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/30 14:42:54 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : m_name{"Form"}, m_isSigned{false}, 
            m_gradeToSign{25}, m_gradeToExecute{10} {}

Form::Form(const std::string& n, bool s, unsigned int gs, unsigned int ge)
    :   m_name{n}, m_isSigned{s}, m_gradeToSign{gs}, m_gradeToExecute{ge}
{
    if (m_gradeToSign < 1 || m_gradeToExecute < 1)
        throw GradeTooHighException("Form: Grade too High");
    else if (m_gradeToSign > 150 || m_gradeToExecute > 150)
        throw GradeTooLowException("Form: Grade too Low");
}

Form::Form(const Form& other) : m_name{other.m_name},
    m_isSigned{other.m_isSigned}, m_gradeToSign{other.m_gradeToSign},
    m_gradeToExecute{other.m_gradeToExecute}
{}

Form&   Form::operator=(const Form& rhs)
{
    if (this != &rhs)
        m_isSigned = rhs.m_isSigned;
    return (*this);
}

Form::~Form(void) {}

const std::string&  Form::getName(void) const
{
    return (m_name);
}

bool    Form::getSign(void) const
{
    return (m_isSigned);
}

unsigned int    Form::getGradeToSign(void) const
{
    return (m_gradeToSign);
}

unsigned int    Form::getGradeToExecute(void) const
{
    return (m_gradeToExecute);
}

void    Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= m_gradeToSign)
        m_isSigned = true;
    else
        throw GradeTooLowException("Grade is too low");
}

std::ostream&   operator<<(std::ostream& os, const Form& f)
{
    os << std::boolalpha;
    os << f.getName() << " " << f.getSign() << " " << f.getGradeToSign()
       << " " << f.getGradeToExecute();
    return (os);
}

//Exceptions
Form::GradeTooHighException::GradeTooHighException(void)
    :   range_error("Form: Grade too High") {}
Form::GradeTooHighException::GradeTooHighException(const char* e)
    :   range_error(e)
{}

Form::GradeTooLowException::GradeTooLowException(void)
    :   range_error("Form: Grade too Low") {}
Form::GradeTooLowException::GradeTooLowException(const char* e)
    :   range_error(e)
{}








