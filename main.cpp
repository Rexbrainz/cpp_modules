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
    Bureaucrat  b{"Douglas", 1};
    try
    {
        b.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& b)
    {
        std::cerr << b.getMsg() << std::endl;
    }
    return (0);
}
