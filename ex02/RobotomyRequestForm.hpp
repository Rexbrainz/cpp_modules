/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:28:21 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/02 11:01:27 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

struct Bureaucrat;

struct  RobotomyRequestForm :   AForm
{
    RobotomyRequestForm() = delete;
    RobotomyRequestForm(const std::string&);
    RobotomyRequestForm(const RobotomyRequestForm&);
    RobotomyRequestForm&    operator=(const RobotomyRequestForm&);
    ~RobotomyRequestForm();

    void    execute(Bureaucrat const&) const;
  private:
    std::string m_target;
};

#endif
