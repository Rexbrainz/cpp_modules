/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:26:13 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/24 12:01:32 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

struct  WrongAnimal
{
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal&);
    virtual ~WrongAnimal(void);
    WrongAnimal&        operator=(const WrongAnimal&);
    const std::string&  getType(void) const;
    void                makeSound(void) const;
  protected:
    std::string type;
};

#endif
