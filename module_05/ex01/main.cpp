/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:28:35 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/30 14:58:15 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat  a{"Rex", 4};
    Bureaucrat  b;
    Form        f1{"Employment", false, 25, 10};

    std::cout << "Form1: " << f1 << std::endl;
    try
    {
        b.signForm(f1);
    }
    catch (Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << b << std::endl;
    try
    {
        a.signForm(f1);
    }
    catch (Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << a << std::endl;
    std::cout << f1 << std::endl;
    std::cout << a << " and " << f1 << std::endl;
    return (0);
}
