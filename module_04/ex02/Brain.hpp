/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 06:43:53 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 07:08:47 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <cstddef>

const int   SIZE = 100;

struct  Brain
{
    Brain(void);
    Brain(const Brain&);
    ~Brain(void);
    Brain&  operator=(const Brain&);
    std::string ideas[SIZE];
};

#endif
