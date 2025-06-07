/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_and_identify.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:48:03 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/07 16:54:23 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void)
{
    std::random_device  seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> roll(0, 2);

    switch  (roll(gen))
    {
        case 0:
            return (new A());
        case 1:
            return (new B());
        default:
            return (new C());
    }
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::bad_cast&)
    {
        try
        {
            B b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (const std::bad_cast&)
        {
            try
            {
                C c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch (const std::bad_cast&)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}
