/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 06:21:42 by sudaniel          #+#    #+#             */
/*   Updated: 2025/07/24 13:22:10 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <chrono>

template <typename Container>
struct Pair
{
    int index { };
    Container   element_b;
    Container   element_a;
    bool        partial { false };
};

template<typename Container>
struct LabeledElement
{
    char        c;
    int         index { };
    Container   element;
};

template<typename ElementContainer, template <typename ...> typename Container>
struct Merged
{
    Container<Pair<ElementContainer>>   pairs;
    ElementContainer                    left_over;
    int                                 pair_size;
};

struct PmergeMe final
{
    PmergeMe() = default;
    PmergeMe(const PmergeMe&) = delete;
    ~PmergeMe() = default;
    PmergeMe& operator=(const PmergeMe&) = delete;

    using   VecElement = std::vector<int>;
    using   VecPair = Pair<std::vector<int>>;
    using   VecMergedPairs = Merged<std::vector<int>, std::vector>;

    using   DeqElement = std::deque<int>;
    using   DeqPair = Pair<std::deque<int>>;
    using   DeqMergedPairs = Merged<std::deque<int>, std::deque>;

    void    sort(std::deque<int>);
    void    sort(std::vector<int>);

    std::vector<int>    getSequenceToSort() const;
    std::vector<int>    getVectorResult() const;
    int                 getSize() const;
    int                 getNumOfComparisons() const;
    time_t              getTime() const;
    std::deque<int>     getDequeResult() const;
  private:
    //Vector section
    VecMergedPairs   merge_sequence(std::vector<int>, int);
    void    initialize_chains(const std::vector<VecPair>&,
                              std::vector<LabeledElement<std::vector<int>>>&,
                              std::vector<LabeledElement<std::vector<int>>>&);
    std::vector<int> generate_jacobsthal_numbers_vec(int);
    void        insertion(std::vector<LabeledElement<std::vector<int>>>&,
                          const std::vector<LabeledElement<std::vector<int>>>::const_iterator);
    void        insert_pend_into_main(std::vector<LabeledElement<std::vector<int>>>&,
                                      std::vector<LabeledElement<std::vector<int>>>&);
    std::vector<int> make_final_sequence(std::vector<LabeledElement<std::vector<int>>>&);
    std::vector<Pair<std::vector<int>>>    make_pairs(std::vector<LabeledElement<std::vector<int>>>&,
                                                      int, std::vector<int>&);
    std::vector<int> init_chains_and_insert(std::vector<VecPair>&,
                                            int, std::vector<int>&);
    //Deque section
    DeqMergedPairs<std::deque<int>, std::deque>  merge_sequence(std::deque<int>);
    void    initialize_chains(const std::deque<DeqPair>&,
                              std::deque<LabeledElement<std::deque<int>>>&,
                              std::deque<LabeledElement<std::deque<int>>>&);
    std::deque<int> generate_jacobsthal_numbers_deq(int);
    void        insertion(std::deque<LabeledElement<std::deque<int>>>&,
                        const std::deque<LabeledElement<std::deque<int>>>::const_iterator);
    void        insert_pend_into_main(std::deque<LabeledElement<std::deque<int>>>&,
                                      std::deque<LabeledElement<std::deque<int>>>&);
    std::deque<int> make_final_sequence(std::deque<LabeledElement<std::deque<int>>>&);
    std::deque<Pair<std::deque<int>>>    make_pairs(std::deque<LabeledElement<std::deque<int>>>&,
                                                    int, std::deque<int>&);
    std::deque<int> init_chains_and_insert(std::deque<DeqPair>,
                                           int, std::deque<int>&);

    bool                compare(int, int b);

    int                 m_number_of_comparisons { };
    std::vector<int>    m_vec_result;
    std::deque<int>     m_deq_result;
    std::vector<int>    m_sequence_to_sort;
    time_t              m_time_taken;
};

std::ostream&    operator<<(std::ostream&, const PmergeMe&);
// std::ostream&    operator<<(const std::ostream&, const PmergeMe&);

#endif

