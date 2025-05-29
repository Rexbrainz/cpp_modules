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
    ~Bureaucrat(void);
    void    incrementGrade(void);
    void    decrementGrade(void);
    std::string     getName(void) const;
    unsigned int    getGrade(void) const;

    struct GradeTooHighException
    {
        GradeTooHighException(void);
        GradeTooHighException(const char*);
        ~GradeTooHighException(void);
        const char* getMsg(void) const;
      private:
        const char* m_msg = "Grade too high";
    };
    struct GradeTooLowException
    {
        GradeTooLowException(void);
        GradeTooLowException(const char*);
        ~GradeTooLowException(void);
        const char* getMsg(void) const;
      private:
        const char* m_msg = "Grade too low";
    };
  private:
    const std::string   m_name;
    unsigned int         m_grade;
};

std::ostream&    operator<<(std::ostream&, Bureaucrat&);


#endif
