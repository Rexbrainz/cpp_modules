/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:14:04 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/30 18:04:22 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

AForm::AForm(void) : m_name{"Form"}, m_isSigned{false}, 
            m_gradeToSign{25}, m_gradeToExecute{10} {}

AForm::AForm(const std::string& n, bool s, unsigned int gs, unsigned int ge)
    :   m_name{n}, m_isSigned{s}, m_gradeToSign{gs}, m_gradeToExecute{ge}
{
    if (m_gradeToSign < 1 || m_gradeToExecute < 1)
        throw GradeTooHighException("Form: Grade too High");
    else if (m_gradeToSign > 150 || m_gradeToExecute > 150)
        throw GradeTooLowException("Form: Grade too Low");
}

AForm::AForm(const AForm& other) : m_name{other.m_name},
    m_isSigned{other.m_isSigned}, m_gradeToSign{other.m_gradeToSign},
    m_gradeToExecute{other.m_gradeToExecute}
{}

AForm&   AForm::operator=(const AForm& rhs)
{
    if (this != &rhs)
        m_isSigned = rhs.m_isSigned;
    return (*this);
}

AForm::~AForm(void) {}

const std::string&  AForm::getName(void) const
{
    return (m_name);
}

bool    AForm::getSign(void) const
{
    return (m_isSigned);
}

unsigned int    AForm::getGradeToSign(void) const
{
    return (m_gradeToSign);
}

unsigned int    AForm::getGradeToExecute(void) const
{
    return (m_gradeToExecute);
}

void    AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= m_gradeToSign)
        m_isSigned = true;
    else
        throw GradeTooLowException("Grade is too low");
}

bool    AForm::verifyExecPermission(const Bureaucrat& b) const 
{
    return (b.getGrade() <= m_gradeToExecute);
}

std::ostream&   operator<<(std::ostream& os, const AForm& f)
{
    os << std::boolalpha;
    os << f.getName() << " " << f.getSign() << " " << f.getGradeToSign()
       << " " << f.getGradeToExecute();
    return (os);
}

//Exceptions
AForm::GradeTooHighException::GradeTooHighException(void)
    :   range_error("Form: Grade too High") {}
AForm::GradeTooHighException::GradeTooHighException(const char* e)
    :   range_error(e)
{}

AForm::GradeTooLowException::GradeTooLowException(void)
    :   range_error("Form: Grade too Low") {}
AForm::GradeTooLowException::GradeTooLowException(const char* e)
    :   range_error(e)
{}

