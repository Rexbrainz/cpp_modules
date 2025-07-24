/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:57:01 by sudaniel          #+#    #+#             */
/*   Updated: 2025/07/24 17:43:21 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main()
{

    std::vector<int> s {2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    // std::vector<int> s { 10, 45, 2, 9};

    PmergeMe   test; 
    test.sort(s);
    //print(merged.new_sequence, merged.pairs, merged.rest);
    //cout << "Merged part went through" << endl;
    //cout << "pair size" << merged.pair_size << endl;
   // auto result { initAndInsert(merged.pairs, merged.pair_size, merged.rest, count)};
   //  std::cout << "number of comparisons are: " << count << std::endl;
   //  std::cout << "Final result:";
   //  for (int i : result)
   //     std::cout << i << " ";
   //  std::cout << std::endl;
   //
    std::cout << test << std::endl;
    return (0);
}
