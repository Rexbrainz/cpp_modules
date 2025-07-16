/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:49:07 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/12 16:53:18 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "====== Basic Push/Pop/Top Test ======\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << "\n"; // should be 17
    mstack.pop();
    std::cout << "Top after pop: " << mstack.top() << "\n"; // should be 5
    std::cout << "Size: " << mstack.size() << "\n"; // should be 1

    std::cout << "====== Adding more elements ======\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Size after more pushes: " << mstack.size() << "\n"; // should be 5

    std::cout << "====== Iterating (mutable) ======\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    for (; it != ite; ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "====== Iterating (const) ======\n";
    const MutantStack<int> cmstack = mstack;
    MutantStack<int>::const_iterator cit = cmstack.begin();
    MutantStack<int>::const_iterator cite = cmstack.end();
    for (; cit != cite; ++cit)
        std::cout << *cit << " ";
    std::cout << "\n";

    std::cout << "====== Copy Constructor Test ======\n";
    MutantStack<int> copyStack(mstack);
    for (auto val : copyStack)
        std::cout << val << " ";
    std::cout << "\n";

    std::cout << "====== Copy Assignment Test ======\n";
    MutantStack<int> assignStack;
    assignStack = mstack;
    for (auto val : assignStack)
        std::cout << val << " ";
    std::cout << "\n";

    std::cout << "====== Move Constructor Test ======\n";
    MutantStack<int> moveStack(std::move(mstack));
    for (auto val : moveStack)
        std::cout << val << " ";
    std::cout << "\n";

    std::cout << "====== Move Assignment Test ======\n";
    MutantStack<int> moveAssignStack;
    moveAssignStack = std::move(copyStack);
    for (auto val : moveAssignStack)
        std::cout << val << " ";
    std::cout << "\n";

    std::cout << "====== Original moved-from stacks state ======\n";
    std::cout << "mstack size (moved-from): " << mstack.size() << "\n"; // likely 0
    std::cout << "copyStack size (moved-from): " << copyStack.size() << "\n"; // likely 0

    return 0;
}
