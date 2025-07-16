#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: program_name RPN_expression" << std::endl;
        return (0);
    }
    RPN rpn;
    try
    {
        int result { rpn.calculate(argv[1]) };
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}

