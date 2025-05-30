/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:14:24 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/30 16:44:46 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

struct Bureaucrat;

struct  AForm
{
    AForm(void);
    AForm(const std::string&, bool, unsigned int, unsigned int);
    AForm(const AForm&);
    AForm&   operator=(const AForm&);
    virtual ~AForm(void);
    const std::string&  getName(void) const;
    bool                getSign(void) const;
    unsigned int        getGradeToSign(void) const;
    unsigned int        getGradeToExecute(void) const;
    void                beSigned(const Bureaucrat&);
    bool                verifyExecPermission(const Bureaucrat&) const;
    virtual void        execute(Bureaucrat const&) const = 0;

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

std::ostream&   operator<<(std::ostream&, const AForm&);

#endif
