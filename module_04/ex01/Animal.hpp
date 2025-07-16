/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 07:08:24 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/24 11:59:57 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

struct  Animal
{
    Animal(void);
    Animal(const Animal&);
    virtual ~Animal(void);
    Animal&             operator=(const Animal&);
    const std::string&  getType(void) const;
    virtual void        makeSound(void) const;
  protected:
    std::string type;
};

#endif
