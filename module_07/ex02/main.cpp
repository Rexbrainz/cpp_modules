#include "Array.hpp"

#define MAX_VAL 75

int main()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        mirror[i] = numbers[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        for (decltype(numbers.size()) i = 0; i < 20; ++i)
            std::cout << numbers[i] << " ";
        std::cout << std::endl << std::endl;
        for (decltype(tmp.size()) i = 0; i < 20; ++i)
            std::cout << tmp[i] << " ";
        std::cout << std::endl << std::endl;
        for (decltype(tmp.size()) i = 0; i < 20; ++i)
            std::cout << tmp[i] << " ";
        std::cout << std::endl << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    delete [] mirror;
    return (0);
}
