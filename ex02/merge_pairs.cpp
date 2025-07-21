#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using Element = vector<int>;

struct  LabeledPairs
{
    int index {};
    Element element_b;
    Element element_a;
    bool    partial_pair { false };
};

struct LabeledElement
{
    char    c;
    int     index { };
    Element element;
};

struct MergedAndRest
{
    vector<LabeledPairs>    pairs;
    vector<int>             rest;
    vector<int>             new_sequence;
    int                     pair_size;
};

using Pair = vector<Element>;

bool    compare(int a, int b, int* numOfComparisons)
{
    ++(*numOfComparisons);
    return (a > b);
}

void    print(vector<int> s, vector<LabeledPairs> pairs, vector<int> remaining)
{
    cout << "Sequence before merging and sorting" << endl;
    for (auto i : s)
        cout << i << " ";
    cout << endl;
    cout << "swapped pairs" << endl;
    for (const auto& element : pairs)
    {
        cout << "(";
        cout << "b"<< element.index << ": (";
        for (auto i : element.element_b)
            cout << i << " ";
        cout << ")";
        if (element.partial_pair)
            cout << "a" << element.index << ": (partial))";
        else
        {
            cout << " a" << element.index << ": (";
            for (auto i : element.element_a)
                cout << i << " ";
            cout << "))";
        }
    }
    cout << "\n The remaining: " << endl;
    for (auto i : remaining)
        cout << i << " ";
    cout << endl;
}

MergedAndRest    merge_sequence(vector<int> sequence, int pair_size, int& count)
{
    vector<int>             remaining_numbers;
    vector<LabeledPairs>    labeled_pairs;
    int                     index { };
    
    size_t i { };
    for (; i + pair_size <= sequence.size(); i += pair_size)
    {
        //handle first element of a pair
        Element element_b(sequence.begin() + i, sequence.begin() + i + pair_size / 2);
        Element element_a(sequence.begin() + i + pair_size / 2, sequence.begin() + i + pair_size);
        if (compare(element_b.back(), element_a.back(), &count))
            swap(element_b, element_a); 
        labeled_pairs.push_back({++index, element_b, element_a});
    }
    int half_pair { pair_size / 2 };
    size_t remaining { sequence.size() - i };
    if (remaining >= (size_t)half_pair)
    {
        Element element_b(sequence.begin() + i, sequence.begin() + i + half_pair);
        labeled_pairs.push_back({++index, element_b, {}, true});
        i += half_pair;
    }
    if (i < sequence.size())
        remaining_numbers.insert(end(remaining_numbers), begin(sequence) + i, end(sequence));
    if (labeled_pairs.size() <= 1)
        return {labeled_pairs, remaining_numbers, sequence, pair_size};
    vector<int> new_sequence;
    for (const auto& e : labeled_pairs)
    {
        new_sequence.insert(end(new_sequence), begin(e.element_b), end(e.element_b));
        new_sequence.insert(end(new_sequence), begin(e.element_a), end(e.element_a));
    }
    if (!remaining_numbers.empty())
        new_sequence.insert(end(new_sequence), begin(remaining_numbers), end(remaining_numbers));
    return merge_sequence(new_sequence, pair_size * 2, count);
}


void    initialize_chains(const vector<LabeledPairs>& l_p,
                          vector<LabeledElement>& main,
                          vector<LabeledElement>& pend)
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

vector<int> generateJacobsThalNumbers(int n)
{
    vector<int> j_numbers {0, 1};

    int j { 2 };
    for (;;)
    {
        int next { j_numbers[j - 1] + 2 * j_numbers[j - 2] };
        if (next >= n)
            break ;
        j_numbers.push_back(next);
    }
    return { begin(j_numbers) + 2, end(j_numbers) };
}

void    insert(vector<LabeledElement>& main,
               const vector<LabeledElement>::const_iterator it,
               int& count)
{
    vector<LabeledElement>  insertion_area;

    for (auto b { begin(main) }; b != end(main); ++b)
    {
        if (b->c == 'a' && (*it).index == b->index)
            break ;
        insertion_area.push_back(*b);
    }
    auto low { begin(insertion_area) };
    auto high { end(insertion_area) };
    while (low < high)
    {
        auto mid { low + (high - low) / 2 };
        if (compare(mid->element.back(), (*it).element.back(), &count))
            high = mid;
        else
            low = mid + 1;
    }
    main.insert(low, it, it + 1);
}

void    insert_pend_into_main(vector<LabeledElement>& main, vector<LabeledElement>& pend, int& count)
{
    if (pend.empty())
        return ;

    vector<int> j_numbers { generateJacobsThalNumbers(pend.size()) };

    int index { };
    while (index < j_numbers.size())
    {
        int j { j_numbers[++index] };
        while (j > j_numbers[index - 1])
        {
            // pend is initialized at pos 0 with b2, so j_number n 
            // is always at n - 2 in the pend chain
            auto it { begin(pend) + j - 2 };
            insert(main, it, count);
            pend.erase(it);
            --j;
        }
    }
    if (!pend.empty())
    {
        while (!pend.empty())
        {
            auto e = end(pend) - 1;
            insert(main, e, count);
            pend.erase(e);
        }
    }
}

vector<int> make_final_sequence(vector<LabeledPairs>& pairs)
{
    vector<int> sequence;

    for (auto& e : pairs)
    {
        sequence.insert(end(sequence), begin(e.element_b), end(e.element_b));
        sequence.insert(end(sequence), begin(e.element_a), end(e.element_a));
    }
    return (sequence);
}
vector<LabeledPairs>    make_pairs(vector<LabeledElement> main,
                                   int pair_size, vector<int> rest)
{
    vector<int>             new_sequence;
    vector<LabeledPairs>    pairs;
    int                     index { };
    int                     element_size { pair_size / 2 };

    //Make sequence
    for (auto& e : main)
        new_sequence.insert(end(new_sequence), begin(e.element), end(e.element));
    new_sequence.insert(end(new_sequence), begin(rest), end(rest));
    //Form complete pairs
    auto b { begin(new_sequence) };
    auto e { end(new_sequence) };
    for (; b + pair_size <= e;)
    {
        Element  elementB { b, b + element_size };
        b += element_size;
        Element  elementA { b, b + element_size };
        LabeledPairs    aPair { ++index, elementB, elementA };
        pairs.push_back(aPair);
        b += element_size;
    }
    //If enough for an element, form a partial pair
    if (b + element_size != e)
    {
        Element  elementB { b, b + element_size };
        LabeledPairs    partial_pair { ++index, elementB, {}, true };
        pairs.push_back(partial_pair);
        b += element_size;
    }
    //Add remaining elements to rest
    if (b != e)
        rest.insert(end(rest), b, e);
    return (pairs);
}
vector<int>    initAndInsert(vector<LabeledPairs>& pairs, vector<int>& rest,
                      int& count)
{
    vector<LabeledElement>  main;
    vector<LabeledElement>  pend;
    size_t                  new_pair_size { pairs.front().element_b.size() * 2 };
    size_t                  element_size { new_pair_size / 2 };

    if (!element_size)
        return make_final_sequence(pairs);
    initialize_chains(pairs, main, pend);
    insert_pend_into_main(main, pend, count);
    auto new_pairs { make_pairs(main, new_pair_size, rest) };
    return (initAndInsert(new_pairs, rest, count));
}

int main()
{

    vector<int> s {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    int count { };

    auto merged { merge_sequence(s, 2, count) };
    auto result { initAndInsert(merged.pairs, merged.rest, count)};
    cout << "number of comparisons are: " << count << endl;
    cout << "Final result:";
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    
    return (0);
}
