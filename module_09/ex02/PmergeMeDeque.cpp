/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 06:20:51 by sudaniel          #+#    #+#             */
/*   Updated: 2025/07/25 10:58:53 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool    PmergeMe::compare_deq(int a, int b)
{
    ++m_number_of_comparisons_deq;
    return (a > b);
}

void    PmergeMe::sort_deq()
{
    std::deque<int>    d_sequence(begin(m_sequence), end(m_sequence));
    auto    start { std::chrono::steady_clock::now() };
    auto merged { merge_sequence(d_sequence, PAIR_SIZE) };
    m_deq_result = init_chains_and_insert(merged.pairs, 
                                  merged.pair_size, merged.left_over);
    auto    end { std::chrono::steady_clock::now() };
    m_time_deq = 
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

PmergeMe::DeqMergedPairs   
PmergeMe::merge_sequence(std::deque<int> sequence, int pair_size)
{
    std::deque<int>        remaining_numbers;
    std::deque<DeqPair>    labeled_pairs;
    int                     index { };
    
    //Make pairs
    size_t i { };
    for (; i + pair_size <= sequence.size(); i += pair_size)
    {
        DeqElement element_b(sequence.begin() + i, sequence.begin() + i + pair_size / 2);
        DeqElement element_a(sequence.begin() + i + pair_size / 2, sequence.begin() + i + pair_size);
        if (compare_deq(element_b.back(), element_a.back()))
            swap(element_b, element_a); 
        labeled_pairs.push_back({++index, element_b, element_a});
    }
    //Can an element be formed?
    int half_pair { pair_size / 2 };
    size_t remaining { sequence.size() - i };
    if (remaining >= static_cast<size_t>(half_pair))
    {
        DeqElement element_b(sequence.begin() + i, sequence.begin() + i + half_pair);
        labeled_pairs.push_back({++index, element_b, {}, true});
        i += half_pair;
    }
    //Get the left over numbers that could not form an element
    if (i < sequence.size())
        remaining_numbers.insert(end(remaining_numbers), begin(sequence) + i, end(sequence));
    //Base case
    if (labeled_pairs.size() <= 1)
        return {labeled_pairs, remaining_numbers, pair_size};
    //New sequence for the next recursion.
    std::deque<int> new_sequence;
    for (const auto& e : labeled_pairs)
    {
        new_sequence.insert(end(new_sequence), begin(e.element_b), end(e.element_b));
        new_sequence.insert(end(new_sequence), begin(e.element_a), end(e.element_a));
    }
    if (!remaining_numbers.empty())
        new_sequence.insert(end(new_sequence), begin(remaining_numbers), end(remaining_numbers));
    return merge_sequence(new_sequence, pair_size * 2);
}

void    PmergeMe::initialize_chains(const std::deque<DeqPair>& l_p,
                          std::deque<LabeledElement<std::deque<int>>>& main,
                          std::deque<LabeledElement<std::deque<int>>>& pend)
{
    auto b { begin(l_p) };
    auto e { end(l_p) };

    main.push_back({'b', b->index, b->element_b});
    main.push_back({'a', b->index, b->element_a});
    ++b;
    while (b != e)
    {
        if (!b->element_a.empty())
            main.push_back({'a', b->index, b->element_a});
        pend.push_back({'b', b->index, b->element_b});
        ++b;
    }
}

std::deque<int> PmergeMe::generate_jacobsthal_numbers_deq(int n)
{
    std::deque<int> j_numbers {0, 1};

    int j { 2 };
    while (true)
    {
        int next { j_numbers[j - 1] + 2 * j_numbers[j - 2] };
        j_numbers.push_back(next);
        if (next > n)
            break ;
        ++j;
    }
    return { begin(j_numbers) + 2, end(j_numbers) };
}

void    PmergeMe::insertion(std::deque<LabeledElement<std::deque<int>>>& main,
               const std::deque<LabeledElement<std::deque<int>>>::const_iterator it)
{
    auto  insertion_area_end { end(main) };

    //Get insertion area
    for (auto b { begin(main) }; b != end(main); ++b)
    {
        if (b->c == 'a' && it->index == b->index)
        {
            insertion_area_end = b;
            break ;
        }
    }
    // Perform binary search
    auto low { begin(main) };
    auto high { insertion_area_end };
    while (low < high)
    {
        auto mid { low + (high - low) / 2 };
        if (compare_deq(mid->element.back(), (*it).element.back()))
            high = mid;
        else
            low = mid + 1;
    }
    main.insert(low, *it);
}

void    
PmergeMe::insert_pend_into_main(std::deque<LabeledElement<std::deque<int>>>& main,
                                    std::deque<LabeledElement<std::deque<int>>>& pend)
{
    if (pend.empty())
        return ;

    std::deque<int> j_numbers { generate_jacobsthal_numbers_deq(pend.size()) };
    if (j_numbers.empty())
        return ;
    std::deque<bool> inserted(pend.size(), false);
    for (size_t i { 1 }; i < j_numbers.size(); ++i)
    {

        int j { j_numbers[i] };
        int prev_j { j_numbers[i - 1] };
        for (int k { j - 1 }; k >= prev_j; --k)
        {
            if (k - 1 < 0 || static_cast<size_t>(k - 1) >= pend.size())
                break ;
            if (!inserted[k - 1])
            {
                insertion(main, begin(pend) + k - 1);
                inserted[k - 1] = true;
            }
        }
    }
    for (int i { static_cast<int>(pend.size()) - 1 }; i >= 0; --i)
    {
        if (!inserted[i])
            insertion(main, begin(pend) + i);
    }
    pend.clear();
}

std::deque<int> 
PmergeMe::make_final_sequence(std::deque<LabeledElement<std::deque<int>>>& main)
{

    std::deque<int> sequence;

    for (auto& e : main)
        sequence.insert(end(sequence), begin(e.element), end(e.element));
    return (sequence);
}

std::deque<PmergeMe::DeqPair>
PmergeMe::make_pairs(std::deque<LabeledElement<std::deque<int>>> &main,
                                   int pair_size, std::deque<int> &rest)
{
    std::deque<int>        new_sequence;
    std::deque<DeqPair>    pairs;
    int                     index { };
    int                     element_size { pair_size / 2 };

    //Make sequence
    for (auto& e : main)
        new_sequence.insert(end(new_sequence), begin(e.element), end(e.element));
    new_sequence.insert(end(new_sequence), begin(rest), end(rest));
    rest.clear();
    //Form complete pairs
    auto b { begin(new_sequence) };
    auto e { end(new_sequence) };
    for (; b + pair_size <= e;)
    {
        auto mid { b + element_size };
        DeqElement  elementB { b, mid };
        DeqElement  elementA { mid, mid + element_size };
        DeqPair    aPair { ++index, elementB, elementA };
        pairs.push_back(aPair);
        b += pair_size;
    }
    //If enough for an element, form a partial pair
    if (distance(b, e) >= element_size)
    {
        DeqElement  elementB { b, b + element_size };
        DeqPair    partial_pair { ++index, elementB, {}, true };
        pairs.push_back(partial_pair);
        b += element_size;
    }
    //Add remaining elements to rest
    if (b != e)
        rest.insert(end(rest), b, e);
    return (pairs);
}

std::deque<int>    
PmergeMe::init_chains_and_insert(std::deque<DeqPair>& pairs,
                            int pair_size, std::deque<int>& rest)
{
    std::deque<LabeledElement<std::deque<int>>>  main;
    std::deque<LabeledElement<std::deque<int>>>  pend;
    int                                            new_pair_size;

    if (pair_size == 2)
    {
        initialize_chains(pairs, main, pend);
        insert_pend_into_main(main, pend);
        return (make_final_sequence(main)); 
    }
    initialize_chains(pairs, main, pend);
    insert_pend_into_main(main, pend);
    new_pair_size = pair_size / 2;
    auto new_pairs { make_pairs(main, new_pair_size, rest) };
    return (init_chains_and_insert(new_pairs, new_pair_size, rest));
}


