/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:28:35 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/02 13:06:46 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
    // Prepare some bureaucrats of various grades
    Bureaucrat highRank("Alice", 1);
    Bureaucrat midRank("Bob", 75);
    Bureaucrat lowRank("Charlie", 150);

    // Prepare forms with various required grades (assumed constructors)
    ShrubberyCreationForm shrub("Home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << "\n-- Signing attempts --\n";

    // High rank bureaucrat signs all forms (should succeed)
    highRank.signForm(shrub);
    highRank.signForm(robot);
    highRank.signForm(pardon);

    // Mid rank bureaucrat tries to sign forms - only allowed if grade sufficient
    midRank.signForm(shrub);  // likely to succeed or fail depending on form's gradeToSign
    midRank.signForm(robot);
    midRank.signForm(pardon);

    // Low rank bureaucrat tries to sign forms - expected to fail
    lowRank.signForm(shrub);
    lowRank.signForm(robot);
    lowRank.signForm(pardon);

    std::cout << "\n-- Execution attempts --\n";

    // High rank bureaucrat tries to execute all forms (should succeed)
    try {
        highRank.executeForm(shrub);
        highRank.executeForm(robot);
        highRank.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << "Execution error: " << e.what() << std::endl;
    }

    // Mid rank bureaucrat tries to execute forms
    try {
        midRank.executeForm(shrub);
        midRank.executeForm(robot);
        midRank.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Low rank bureaucrat tries to execute forms (should fail)
    try {
        lowRank.executeForm(shrub);
        lowRank.executeForm(robot);
        lowRank.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n-- Attempting to execute unsigned form --\n";
    RobotomyRequestForm unsignedForm("Unsigned");
    try {
        highRank.executeForm(unsignedForm);  // should throw since unsigned
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n-- Testing grade increments and decrements with exceptions --\n";
    try {
        Bureaucrat tooHigh("TopDog", 1);
        tooHigh.incrementGrade(); // should throw GradeTooHighException
    } catch (const std::exception& e) {
        std::cout << "Expected exception on increment: " << e.what() << std::endl;
    }

    try {
        Bureaucrat tooLow("BottomDog", 150);
        tooLow.decrementGrade(); // should throw GradeTooLowException
    } catch (const std::exception& e) {
        std::cout << "Expected exception on decrement: " << e.what() << std::endl;
    }

    std::cout << "\n-- Printing Bureaucrat and Form info --\n";
    std::cout << highRank << std::endl;
    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    return 0;
}
