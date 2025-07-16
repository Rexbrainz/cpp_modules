/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 07:51:16 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/24 08:44:34 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

struct  Cat : Animal
{
    Cat(void);
    Cat(const Cat&);
    ~Cat(void);
    Cat&    operator=(const Cat&);
    void    makeSound(void) const override;
};

#endif
