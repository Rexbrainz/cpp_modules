/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 08:57:13 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/24 09:03:29 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal*   meta = new Animal();
    const Animal*   j = new Dog();
    const Animal*   i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    //Mine
    Cat   minicat;
    std::cout << "Minicat is a: " << minicat.getType() << std::endl;
    Dog   Hosky;
    std::cout << "Hosky is a: " << Hosky.getType() << std::endl;

    Animal animal;
    animal = minicat;
    Dog dog;
    dog = Hosky;

    const WrongAnimal*  wrongCat = new WrongCat();
    const WrongAnimal   wCat = (WrongCat());
    std::cout << "WrongCat sound: ";
    wrongCat->makeSound();
    wCat.makeSound();


    std::cout << "animal sound: ";
    animal.makeSound();
    std::cout << "Dog sound: ";
    dog.makeSound();
    delete meta;
    delete j;
    delete i;
    delete wrongCat;
    return (0);
}
