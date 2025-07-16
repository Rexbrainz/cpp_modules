/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:03:35 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/11 18:13:32 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <cstdlib>  // for rand()
#include <ctime>    // for time()


int main() 
{
    try {
        std::cout << "Creating Span of size 5...\n";
        Span sp(5);

        std::cout << "Adding numbers...\n";
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << "\n"; // Should output 2 (between 9 and 11)
        std::cout << "Longest Span: " << sp.longestSpan() << "\n";   // Should output 14 (between 3 and 17)

        std::cout << "\nTesting addMultipleNumbers...\n";
        Span sp2(5);
        std::vector<int> values = {100, 200, 300, 400, 500};
        sp2.addMultipleNumbers(values.begin(), values.end());
        std::cout << "sp2 Longest Span: " << sp2.longestSpan() << "\n"; // Should output 400

        std::cout << "\nTesting Copy Constructor...\n";
        Span spCopy(sp2);
        std::cout << "spCopy Longest Span: " << spCopy.longestSpan() << "\n"; // Same as sp2

        std::cout << "\nTesting Copy Assignment...\n";
        Span spAssign(5);
        spAssign = sp;
        std::cout << "spAssign Shortest Span: " << spAssign.shortestSpan() << "\n"; // Same as sp

        std::cout << "\nTesting Move Constructor...\n";
        Span spMove(std::move(sp2));
        std::cout << "spMove Longest Span: " << spMove.longestSpan() << "\n";

        std::cout << "\nTesting Move Assignment...\n";
        Span spMoveAssign(5);
        spMoveAssign = std::move(spCopy);
        std::cout << "spMoveAssign Longest Span: " << spMoveAssign.longestSpan() << "\n";

        std::cout << "\nTesting Exception: Exceeding capacity...\n";
        Span spError(2);
        spError.addNumber(1);
        spError.addNumber(2);
        spError.addNumber(3); // Should throw exception
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    try {
        std::cout << "\nTesting Exception: Span not found...\n";
        Span spEmpty(2);
        spEmpty.addNumber(1);
        std::cout << spEmpty.shortestSpan() << "\n"; // Should throw exception
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}

