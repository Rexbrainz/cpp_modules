/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:00:54 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/29 16:39:38 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat  a{"Douglas", 1};
    Bureaucrat  b{"Abdullah", 150};

    Bureaucrat  d{"Misha", 3};
    std::cout << d << std::endl;

    try
    {
        a.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& aExcept)
    {
        std::cerr << aExcept.getMsg() << std::endl;
    }
    try
    {
        b.decrementGrade();
    }
    catch (const Bureaucrat::GradeTooLowException& bExcept)
    {
        std::cerr << bExcept.getMsg() << std::endl;
    }
    try
    {
        Bureaucrat  c{"Pasha", 157};
    }
    catch (const Bureaucrat::GradeTooLowException cExcept)
    {
        std::cerr << cExcept.getMsg() << std::endl;
    }
    return (0);
}
