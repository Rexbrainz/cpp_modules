/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:01:23 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/27 12:36:05 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
    std::cout << "--- Creating MateriaSource and learning Materia ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n--- Creating Character 'me' and equipping Materia ---" << std::endl;
    ICharacter* me = new Character("me");

    AMateria* tmp = nullptr;
    tmp = src->createMateria("ice");
    if (tmp) me->equip(tmp);
    tmp = src->createMateria("cure");
    if (tmp) me->equip(tmp);

    std::cout << "\n--- Creating Character 'bob' ---" << std::endl;
    ICharacter* bob = new Character("bob");

    std::cout << "\n--- Using Materia on 'bob' ---" << std::endl;
    me->use(0, *bob);  // ice use
    me->use(1, *bob);  // cure use
    me->use(2, *bob);  // invalid index, should do nothing

    std::cout << "\n--- Testing equip limits ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        AMateria* m = src->createMateria("ice");
        me->equip(m);  // the 5th should be dropped to Floor, not equipped
    }

    std::cout << "\n--- Testing unequip ---" << std::endl;
    me->unequip(1);  // unequip cure, should drop to Floor
    me->unequip(10); // invalid index, nothing happens

    std::cout << "\n--- Testing use after unequip ---" << std::endl;
    me->use(1, *bob);  // index 1 now should be next materia after shifting

    std::cout << "\n--- Testing copy constructor ---" << std::endl;
    Character copyMe = *(dynamic_cast<Character*>(me));
    copyMe.use(0, *bob);

    std::cout << "\n--- Testing assignment operator ---" << std::endl;
    Character assigned("assigned");
    assigned = *(dynamic_cast<Character*>(me));
    assigned.use(1, *bob);

    std::cout << "\n--- Cleaning up ---" << std::endl;
    delete bob;
    delete me;
    delete src;

    std::cout << "--- End of test ---" << std::endl;

    //system("leaks interfaces");

    return 0;
}
