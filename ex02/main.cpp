/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:57:01 by sudaniel          #+#    #+#             */
/*   Updated: 2025/07/25 11:00:37 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    
    if (argc < 2)
    {
        std::cerr << "Input: Program name and sequence to sort" << std::endl;
        return (0);
    }

    PmergeMe   merge_insert(argv + 1); 
    merge_insert.sort_vec();
    merge_insert.sort_deq();
    std::cout << merge_insert << std::endl;
    return (0);
}
