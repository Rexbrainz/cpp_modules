/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:58:41 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/02 12:33:20 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& s) 
    :   AForm{"RobotomyRequestForm", false, 72, 45}, m_target{s}
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    :   AForm{other}, m_target{other.m_target}
{}

RobotomyRequestForm&    
    RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        m_target = rhs.m_target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::execute(Bureaucrat const& e) const
{
    if (!getSign())
        throw GradeTooLowException("Execution: Robotomy failed");
    if (!verifyExecPermission(e))
        throw GradeTooLowException("Execution: Robotomy failed");
    std::cout << "krkrkrkrkrkrkrkshshshshskkrkrkrkrkrk" << std::endl;
    std::cout << m_target << " has been robotomised successfully 50% of the time"
              << std::endl;
}

