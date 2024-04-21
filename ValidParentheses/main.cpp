//
// Created by F-Mir on 4/21/2024.
//

#include <cassert>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    static bool isValid(const string& s)
    {
        stack<char> open_brackets;
        for (char letter: s)
        {
            if (letter == '(' or letter == '{' or letter == '[')
            {
                open_brackets.push(letter);
            } else
            {
                if (open_brackets.empty())
                {
                    return false;
                }
                char open_bracket = open_brackets.top();
                bool is_right_order = open_bracket == '(' and letter == ')' or
                                      open_bracket == '[' and letter == ']' or
                                      open_bracket == '{' and letter == '}';
                if (!is_right_order)
                {
                    return false;
                }
                open_brackets.pop();
            }
        }
        return open_brackets.empty();
    }
};

int main()
{
    assert(Solution::isValid("()"));
    assert(Solution::isValid("(){}[]"));
    assert(!Solution::isValid("(]"));
    return 0;
}