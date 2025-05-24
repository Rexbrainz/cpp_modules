/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 07:19:30 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/24 08:43:14 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

struct  Dog : Animal
{
    Dog(void);
    Dog(const Dog&);
    ~Dog(void);
    Dog&    operator=(const Dog&);
    void    makeSound(void) const override;
};

#endif
