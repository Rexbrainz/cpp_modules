/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 07:19:30 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 07:27:06 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

struct  Dog : Animal
{
    Dog(void);
    Dog(const Dog&);
    ~Dog(void);
    Dog&    operator=(const Dog&);
    void    makeSound(void) const override;
  private:
    Brain*  m_brain;
};

#endif
