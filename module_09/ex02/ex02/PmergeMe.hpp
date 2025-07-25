/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 06:21:42 by sudaniel          #+#    #+#             */
/*   Updated: 2025/07/25 10:58:47 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <chrono>
#include <cctype>

constexpr   int PAIR_SIZE = 2;

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
    PmergeMe(char **);
    PmergeMe(const PmergeMe&) = delete;
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe&) = delete;

    using   VecElement = std::vector<int>;
    using   VecPair = Pair<std::vector<int>>;
    using   VecMergedPairs = Merged<std::vector<int>, std::vector>;

    using   DeqElement = std::deque<int>;
    using   DeqPair = Pair<std::deque<int>>;
    using   DeqMergedPairs = Merged<std::deque<int>, std::deque>;
    void    sort_vec();
    void    sort_deq();

    std::vector<int>    getSequenceToSort() const;
    std::vector<int>    getVectorResult() const;
    int                 getSize() const;
    int                 getNumOfComparisonsVec() const;
    int                 getNumOfComparisonsDeq() const;
    long long           getTimeVec() const;
    long long           getTimeDeq() const;
    std::deque<int>     getDequeResult() const;
  private:
    std::vector<int>    validate(char **);
    //Vector section
    VecMergedPairs   merge_sequence(std::vector<int>&, int);
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
    DeqMergedPairs  merge_sequence(std::deque<int>, int);
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
    std::deque<int> init_chains_and_insert(std::deque<DeqPair>&,
                                           int, std::deque<int>&);

    bool    compare_vec(int, int b);
    bool    compare_deq(int, int b);

    int                 m_number_of_comparisons_vec { };
    int                 m_number_of_comparisons_deq { };
    std::vector<int>    m_vec_result;
    std::deque<int>     m_deq_result;
    std::vector<int>    m_sequence;
    std::chrono::microseconds        m_time_vec;
    std::chrono::microseconds        m_time_deq;
};

std::ostream&    operator<<(std::ostream&, const PmergeMe&);

#endif

