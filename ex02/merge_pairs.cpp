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

bool    compare(int a, int b)
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
    //print(sequence, labeled_pairs, remaining_numbers);
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
    cout << "main in init chains -> " << std::flush;
     for (size_t i { 0 }; i < main.size(); ++i)
    {
        cout << "( ";
        for (size_t j { 0 }; j < main[i].element.size(); ++j)
            cout << main[i].element[j] << " ";
        cout << ")";
    }
    cout << endl;
    cout << "pend in init chains -> " << std::flush;
    for (size_t i { 0 }; i < pend.size(); ++i)
    {
        cout << "( ";
        for (size_t j { 0 }; j < pend[i].element.size(); ++j)
            cout << pend[i].element[j] << " ";
        cout << ")";
    }
    cout << endl;
    cout << "initialize chains went through" << endl;
}

vector<int> generateJacobsThalNumbers(int n)
{
    vector<int> j_numbers {0, 1};

    int j { 2 };
    for (;;)
    {
        int next { j_numbers[j - 1] + 2 * j_numbers[j - 2] };
        j_numbers.push_back(next);
        if (next > n)
            break ;
        ++j;
    }
    cout << "Generating jacobsthal part went through" << endl;
    return { begin(j_numbers) + 2, end(j_numbers) };
}

void    insert(vector<LabeledElement>& main,
               const vector<LabeledElement>::const_iterator it,
               int& count)
{
    auto  insert_end { end(main) };

    for (auto b { begin(main) }; b != end(main); ++b)
    {
        if (b->c == 'a' && it->index == b->index)
        {
            insert_end = b;
            break ;
        }
    }
    auto low { begin(main) };
    auto high { insert_end };
    while (low < high)
    {
        auto mid { low + (high - low) / 2 };
        if (compare(mid->element.back(), (*it).element.back(), &count))
            high = mid;
        else
            low = mid + 1;
    }
    main.insert(low, *it);
    cout << "Inserted " << it->c << it->index << endl;
}

void    insert_pend_into_main(vector<LabeledElement>& main, vector<LabeledElement>& pend, int& count)
{
    std::cout << "we are in insert_pend_into_main" << std::endl;
    if (pend.empty())
        return ;

     cout << "main in insert_pend_into_main -> " << std::flush;
     for (size_t i { 0 }; i < main.size(); ++i)
    {
        cout << "( ";
        for (size_t j { 0 }; j < main[i].element.size(); ++j)
            cout << main[i].element[j] << " ";
        cout << ")";
    }
    cout << endl;
    cout << "pend in insert_pend_into_main -> " << std::flush;
    for (size_t i { 0 }; i < pend.size(); ++i)
    {
        cout << "( ";
        for (size_t j { 0 }; j < pend[i].element.size(); ++j)
            cout << pend[i].element[j] << " ";
        cout << ")";
    }
    cout << endl;

    vector<int> j_numbers { generateJacobsThalNumbers(pend.size()) };
    if (j_numbers.empty())
        return ;
    cout << "Pend size: " << pend.size() << ", Jacobsthal: ";
    for (auto j : j_numbers)
        cout << j << " ";
    cout << endl;
    vector<bool> inserted(pend.size(), false);
    for (size_t i { 1 }; i < j_numbers.size(); ++i)
    {

        int j { j_numbers[i] };
        int prev_j { j_numbers[i - 1] };
        for (int k { j - 1 }; k >= prev_j; --k)
        {
            if (k < 0 || static_cast<size_t>(k) >= pend.size())
                break ;
            if (!inserted[k - 1])
            {
                insert(main, begin(pend) + k - 1, count);
                inserted[k - 1] = true;
            }
        }
    }
    for (int i { static_cast<int>(pend.size()) - 1 }; i >= 0; --i)
    {
        if (!inserted[i])
            insert(main, begin(pend) + i, count);
    }
    pend.clear();
    cout << "Successfully inserted pend" << endl;
}

vector<int> make_final_sequence(vector<LabeledElement>& main)
{

    std::cout << "we are in make_final_sequence" << std::endl;
    vector<int> sequence;

    for (auto& e : main)
    {
        sequence.insert(end(sequence), begin(e.element), end(e.element));
    }
    for (auto number : sequence)
        std::cout << number << " ";
    std::cout << " <- this was the sequenc in make_final_sequence" << std::endl;
    return (sequence);
}
vector<LabeledPairs>    make_pairs(vector<LabeledElement> &main,
                                   int pair_size, vector<int> &rest)
{
    std::cout << "we are in make_pairs" << std::endl;
    vector<int>             new_sequence;
    vector<LabeledPairs>    pairs;
    int                     index { };
    int                     element_size { pair_size / 2 };

    //Make sequence
    for (auto& e : main)
        new_sequence.insert(end(new_sequence), begin(e.element), end(e.element));
    new_sequence.insert(end(new_sequence), begin(rest), end(rest));
    rest.clear();
    cout << "new_sequence in make_pairs-> ";
    for (auto i : new_sequence)
        cout << i << " ";
    cout << endl;
    //Form complete pairs
    auto b { begin(new_sequence) };
    auto e { end(new_sequence) };
    for (; b + pair_size <= e;)
    {
        auto mid { b + element_size };
        Element  elementB { b, mid };
        Element  elementA { mid, mid + element_size };
        LabeledPairs    aPair { ++index, elementB, elementA };
        pairs.push_back(aPair);
        b += pair_size;
    }
    //If enough for an element, form a partial pair
    if (distance(b, e) >= element_size)
    {
        Element  elementB { b, b + element_size };
        LabeledPairs    partial_pair { ++index, elementB, {}, true };
        pairs.push_back(partial_pair);
        b += element_size;
    }
    //Add remaining elements to rest
    if (b != e)
        rest.insert(end(rest), b, e);
    cout << "Make pairs went through" << endl;
    return (pairs);
}
vector<int>    initAndInsert(vector<LabeledPairs>& pairs, int pair_size, vector<int>& rest,
                      int& count)
{
    vector<LabeledElement>  main;
    vector<LabeledElement>  pend;
    int                     new_pair_size { pair_size / 2 };

    if (pair_size == 2)
    {
        vector<LabeledElement>  main;
        vector<LabeledElement>  pend;
        initialize_chains(pairs, main, pend);
        insert_pend_into_main(main, pend, count);
        return (make_final_sequence(main)); 
    }
    initialize_chains(pairs, main, pend);
    insert_pend_into_main(main, pend, count);
    auto new_pairs { make_pairs(main, new_pair_size, rest) };
    return (initAndInsert(new_pairs, new_pair_size, rest, count));
}

int main()
{

    // vector<int> s {2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    vector<int> s { 10, 45, 2, 9};
    int count { };

    auto merged { merge_sequence(s, 2, count) };
    //print(merged.new_sequence, merged.pairs, merged.rest);
    //cout << "Merged part went through" << endl;
    //cout << "pair size" << merged.pair_size << endl;
   auto result { initAndInsert(merged.pairs, merged.pair_size, merged.rest, count)};
   cout << "number of comparisons are: " << count << endl;
    cout << "Final result:";
    for (int i : result)
       cout << i << " ";
   cout << endl;
    
    return (0);
}
