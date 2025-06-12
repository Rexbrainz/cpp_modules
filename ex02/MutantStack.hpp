/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:16:27 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/12 16:51:45 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template<typename T>
struct  MutantStack :   std::stack<T>
{
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack&);
    MutantStack&    operator=(const MutantStack&);

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::
                        container_type::const_iterator const_iterator;
    iterator        begin();
    const_iterator  begin() const;
    iterator        end();
    const_iterator  end() const;
};

#include "MutantStack.tpp"

#endif
