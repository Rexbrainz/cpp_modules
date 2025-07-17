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
    int     index { };
    Element element;
};

struct MergedAndRest
{
    vector<LabeledPairs>    pairs;
    vector<int>             rest;
    vector<int>             new_sequence;
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
        return {labeled_pairs, remaining_numbers, sequence};
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


void    initialize_chains(vector<LabeledPairs> l_p, vector<int> rest)
{
    vector<LabeledElement>  main;
    vector<LabeledElement>  pend;
    vector<int>             non_participating;

    auto b { begin(l_p) };
    auto e { end(l_p) };

    main.push_back({b->index, b->element_b});
    main.push_back({b->index, b->element_a});
    ++b;
    while (b != e)
    {
        if (!b->element_a.empty())
            main.push_back({b->index, b->element_a});
        pend.push_back({b->index, b->element_b});
        ++b;
    }

}

int main()
{

    vector<int> s {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    int count { };

    auto result { merge_sequence(s, 2, count) };
    cout << "number of comparisons are: " << count << endl;
    cout << "Final result:";
    print(result.new_sequence, result.pairs, result.rest);
    
    return (0);
}
