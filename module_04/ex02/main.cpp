/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 08:57:13 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/26 09:07:04 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
   // const Animal*   k = new Animal();
    //Animal animal;
    const Animal*   j = new Dog();
    const Animal*   i = new Cat();
    Animal*         meta[10];

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();

    for (size_t i = 0; i < 10; i++)
    {
        if (i < 5)
            meta[i] = new Cat();
        else
            meta[i] = new Dog();
    }
    for (const auto i :  meta)
         i->makeSound();
    for (const auto i : meta)
         delete i;
        
    delete j;
    delete i;
    //system("leaks polymorphism");
    return (0);
}
