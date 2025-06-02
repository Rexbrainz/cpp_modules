/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:05:33 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/02 13:13:11 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

struct Bureaucrat;

struct  PresidentialPardonForm  :   AForm
{
    PresidentialPardonForm() = delete;
    PresidentialPardonForm(const std::string&);
    PresidentialPardonForm(const PresidentialPardonForm&);
    PresidentialPardonForm& operator=(const PresidentialPardonForm&);
    ~PresidentialPardonForm();
    void    execute(Bureaucrat const&) const;
  private:
    std::string m_target;
};

#endif
