/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:40:04 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/02 17:01:21 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>

struct Bureaucrat;


struct  ShrubberyCreationForm : AForm
{
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string&);
    ShrubberyCreationForm(const ShrubberyCreationForm&);
    ShrubberyCreationForm&  operator=(const ShrubberyCreationForm&);
    ~ShrubberyCreationForm();
    void    execute(Bureaucrat const&) const;
  private:
    std::string m_target;
};

#endif
