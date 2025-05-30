/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:40:04 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/30 18:03:49 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"
#include <fstream>

struct  ShrubberyCreationForm : AForm
{
    ShrubberyCreationForm(void) = delete;
    ShrubberyCreationForm(const std::string&);
    ShrubberyCreationForm(const ShrubberyCreationForm&);
    ShrubberyCreationForm&  operator=(const ShrubberyCreationForm&);
    ~ShrubberyCreationForm(void);
    void    execute(Bureaucrat const&) const;
  private:
    std::string m_target;
};


#endif
