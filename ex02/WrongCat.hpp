/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:02:25 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/24 12:07:14 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

struct  WrongCat : WrongAnimal
{
    WrongCat(void);
    WrongCat(const WrongCat&);
    virtual ~WrongCat(void);
    WrongCat&   operator=(const WrongCat&);
    void        makeSound(void) const;
};

#endif
