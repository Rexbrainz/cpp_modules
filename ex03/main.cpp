/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:59:58 by sudaniel          #+#    #+#             */
/*   Updated: 2025/05/21 13:41:12 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
    Point   a(0.0f, 0.0f);
    Point   b(5.0f, 0.0f);
    Point   c(0.0f, 5.0f);

    Point p1(1.0f, 1.0f);
    Point p2(0.0f, 0.0f);
    Point p3(2.5f, 0.0f);
    Point p4(0.0f, 2.5f);
    Point p5(2.5f, 2.5f);
    Point p6(0.1f, 0.1f);
    Point p7(5.0f, 0.0f);
    Point p8(-1.0f, -1.0f);
    Point p9(1.0f, 3.0f);
    Point p10(2.0f, 2.0f);
    Point p11(2.5f, 2.6f);
    Point edgeClose1(2.5f, 2.4999f);
    Point edgeClose2(2.5f, 2.5001f);
    Point tinyInside(0.0001f, 0.0001f);
    Point tinyOutside(-0.0001f, 0.0001f);
    Point vertexClose(0.0f, 0.00001f);
    Point rand1(1.5f, 1.0f);
    Point rand2(3.0f, 1.0f);
    Point rand3(4.5f, 0.1f);
    Point rand4(3.0f, 3.0f);
    Point rand5(-1.0f, -1.0f);

    std::cout << std::boolalpha;
    std::cout << "p1: " << bsp(a, b, c, p1) << std::endl;
    std::cout << "p2: " << bsp(a, b, c, p2) << std::endl;
    std::cout << "p3: " << bsp(a, b, c, p3) << std::endl;
    std::cout << "p4: " << bsp(a, b, c, p4) << std::endl;
    std::cout << "p5: " << bsp(a, b, c, p5) << std::endl;
    std::cout << "p6: " << bsp(a, b, c, p6) << std::endl;
    std::cout << "p7: " << bsp(a, b, c, p7) << std::endl;
    std::cout << "p8: " << bsp(a, b, c, p8) << std::endl;
    std::cout << "p9: " << bsp(a, b, c, p9) << std::endl;
    std::cout << "p10: " << bsp(a, b, c, p10) << std::endl;
    std::cout << "p11: " << bsp(a, b, c, p11) << std::endl;
    std::cout << "edgeClose1: " << bsp(a, b, c, edgeClose1) << std::endl;
    std::cout << "edgeClose2: " << bsp(a, b, c, edgeClose2) << std::endl;
    std::cout << "tinyInside: " << bsp(a, b, c, tinyInside) << std::endl;
    std::cout << "tinyOutside: " << bsp(a, b, c, tinyOutside) << std::endl;
    std::cout << "vertexClose: " << bsp(a, b, c, vertexClose) << std::endl;
    std::cout << "rand1: " << bsp(a, b, c, rand1) << std::endl;
    std::cout << "rand2: " << bsp(a, b, c, rand2) << std::endl;
    std::cout << "rand3: " << bsp(a, b, c, rand3) << std::endl;
    std::cout << "rand4: " << bsp(a, b, c, rand4) << std::endl;
    std::cout << "rand5: " << bsp(a, b, c, rand5) << std::endl;

    return 0;
}
