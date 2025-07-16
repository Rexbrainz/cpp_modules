/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 06:52:06 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 08:44:21 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    for (auto &i : ideas)
        i = "";
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) 
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (size_t i = 0; i < SIZE; i++)
        ideas[i] = other.ideas[i];
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain&  Brain::operator=(const Brain& ro)
{
    if (this == &ro)
        return (*this);
    for (size_t i = 0; i < SIZE; i++)
        ideas[i] = ro.ideas[i];
    std::cout << "Brain assignment operator called" << std::endl;
    return (*this);
}
