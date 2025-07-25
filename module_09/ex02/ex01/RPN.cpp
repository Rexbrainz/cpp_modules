#include "RPN.hpp"

int RPN::pop()
{
    if (m_stack.empty())
        underflow();
    int value { m_stack.top() };
    m_stack.pop();
    return (value);
}

/* 
 * Handling of multiple values could result in cases
 * where addition and multiplication could result to
 *very large numbers, verifyResult simply checks that
 * and throws when such cases arise.
*/
int RPN::operations(int op)
{
    int second { pop() };
    int first { pop() };
    switch (op)
    {
        case '+':
            return (verifyResult(first, second, '+'));
        case '-':
            return (verifyResult(first, second, '-'));
        case '/':
            if (second == 0)
                throw std::runtime_error("Error: division by zero");
            return (verifyResult(first, second, '/'));
        case '*':
            return (verifyResult(first, second, '*'));
        case '%':
            if (second == 0)
                throw std::runtime_error("Error: modulo by zero");
            return (first % second);
        default :
            throw std::runtime_error("Error: invalid character"); 
    }
}

int RPN::calculate(std::string_view arg)
{
    if (arg.empty())
        throw std::runtime_error("Empty RPN expression");
    auto begin { std::begin(arg) }, end { std::end(arg) };
    while (begin != end)
    {
        if (std::isspace(*begin))
        {
            begin++;
            continue ;
        }
        // if it is a negative number, or (multiple) number(s)
        else if ((*begin == '-' &&
            (begin + 1) != end && std::isdigit(*(begin + 1)))
            || std::isdigit(*begin))
        {
            auto [value, newBegin] { getValueAndUpdateIterator(begin, end) };
            m_stack.push(value);
            begin = newBegin;
        }
        else if (isValidOperator(*begin))
        {
            auto op { *begin++ };
            m_stack.push(operations(op));
        }
        else
            throw std::runtime_error("Error: invalid character");
    }
    if (m_stack.size() != 1)
        throw std::runtime_error("Error: too many operands");
    int result { m_stack.top() };
    m_stack.pop();
    return (result);
}

void    RPN::underflow()
{
    throw std::runtime_error("Error: too few operands.");
}

void    RPN::isWithinIntRange(long long value)
{
    const char* error { "Error: result larger or smaller than int" };

    if (value > std::numeric_limits<int>::max() ||
        value < std::numeric_limits<int>::min())
        throw std::runtime_error(error);
}

int RPN::verifyResult(int first, int second, char ch)
{
    int         result { };
    long long   temp { };
    switch (ch)
    {
        case '+':
            temp = static_cast<long long>(first) + static_cast<long long>(second);
            isWithinIntRange(temp);
            result = static_cast<int>(temp);
            break ;
        case '-':
            temp = static_cast<long long>(first) - static_cast<long long>(second);
            isWithinIntRange(temp);
            result = static_cast<int>(temp);
            break ;
        case '*':
            temp = static_cast<long long>(first) * static_cast<long long>(second);
            isWithinIntRange(temp);
            result = static_cast<int>(temp);
            break ;
        case '/':
            if (second == 0)
                throw std::runtime_error("Error: division by zero");
            if (first == std::numeric_limits<int>::min() && second == -1)
                throw std::runtime_error("Error: division overflow");
            temp = static_cast<long long>(first) / static_cast<long long>(second);
            result = static_cast<int>(temp);
            break;
        default:
            throw std::runtime_error("Error: invalid character");
            break ;
    }
    return (result);
}

std::pair<int, std::string_view::const_iterator> 
RPN::getValueAndUpdateIterator(std::string_view::const_iterator begin,
                  std::string_view::const_iterator end)
{
    auto    it { begin };

    while (it != end && !std::isspace(*it))
        ++it;
    const std::string strInt(begin, it);
    int value { };
    size_t  pos { };
    value = stoi(strInt, &pos);
    //if there are invalid characters in strInt, then throw
    if (pos != strInt.size())
        throw std::runtime_error("Error: invalid character");
    return {value, it};
}

bool    RPN::isValidOperator(int ch)
{
    return (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%');
}
