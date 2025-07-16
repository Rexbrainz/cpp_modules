/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:28:35 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/03 14:40:08 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
    Intern intern;
    Bureaucrat alice("Alice", 45);

    // Test valid forms
    AForm* form1 = intern.makeForm("shrubbery creation", "Home");
    AForm* form2 = intern.makeForm("robotomy request", "Bob");
    AForm* form3 = intern.makeForm("presidential pardon", "Charlie");

    AForm* forms[] = { form1, form2, form3 };

    for (int i = 0; i < 3; ++i)
    {
        if (!forms[i])
        {
            std::cout << "Failed to create form " << i << std::endl;
            continue;
        }

        std::cout << *forms[i] << std::endl;

        try
        {
            alice.signForm(*forms[i]);
        }
        catch (AForm::GradeTooLowException& e)
        {
            std::cout << alice.getName() << " couldn't sign " << forms[i]->getName()
                      << " because " << e.what() << std::endl;
        }

        try
        {
            alice.executeForm(*forms[i]);
        }
        catch (AForm::GradeTooLowException& e)
        {
            std::cout << alice.getName() << " couldn't execute " << forms[i]->getName()
                      << " because " << e.what() << std::endl;
        }

        delete forms[i];
    }

    // Test bad form creation
    std::cout << "\n-- Testing bad form creation --" << std::endl;
    AForm* badForm = intern.makeForm("invalid form", "Nobody");
    if (!badForm)
        std::cout << "Bad form creation correctly returned nullptr." << std::endl;
    else
    {
        std::cout << "Error: bad form creation did not return nullptr!" << std::endl;
        delete badForm;
    }

    return 0;
}
