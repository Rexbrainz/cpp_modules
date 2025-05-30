/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:40:06 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/29 16:59:47 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

const       std::string DEFAULT_NAME = "Default";
constexpr   int DEFAULT_GRADE = 75;

struct  Bureaucrat
{
    Bureaucrat(void);
    Bureaucrat(const std::string&, int);
    Bureaucrat(const Bureaucrat&);
    Bureaucrat& operator=(const Bureaucrat&);
    ~Bureaucrat(void);
    void    incrementGrade(void);
    void    decrementGrade(void);
    const std::string&     getName(void) const;
    unsigned int    getGrade(void) const;

    struct GradeTooHighException
    {
        GradeTooHighException(const char* = "Grade too High");
        ~GradeTooHighException(void);
        const char* getMsg(void) const;
      private:
        const char* m_msg;
    };
    
    struct GradeTooLowException
    {
        GradeTooLowException(const char* = "Grade too Low");
        ~GradeTooLowException(void);
        const char* getMsg(void) const;
      private:
        const char* m_msg;
    };

  private:
    const std::string   m_name;
    unsigned int         m_grade = DEFAULT_GRADE;
};

std::ostream&    operator<<(std::ostream&, const Bureaucrat&);

#endif
