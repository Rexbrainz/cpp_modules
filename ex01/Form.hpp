/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:14:24 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/30 12:36:44 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

struct Bureaucrat;

struct  Form
{
    Form(void);
    Form(const std::string&, bool, unsigned int, unsigned int);
    Form(const Form&);
    Form&   operator=(const Form&);
    ~Form(void);
    const std::string&  getName(void) const;
    bool                getSign(void) const;
    unsigned int        getGradeToSign(void) const;
    unsigned int        getGradeToExecute(void) const;
    void                beSigned(const Bureaucrat&);

    struct GradeTooHighException : std::range_error
    {
        GradeTooHighException(void);
        GradeTooHighException(const char*);
    };

    struct GradeTooLowException : std::range_error
    {
        GradeTooLowException(void);
        GradeTooLowException(const char*);
    };

  private:
    const std::string   m_name;
    bool                m_isSigned;
    const unsigned int  m_gradeToSign;
    const unsigned int  m_gradeToExecute;
};

std::ostream&   operator<<(std::ostream&, const Form&);

#endif
