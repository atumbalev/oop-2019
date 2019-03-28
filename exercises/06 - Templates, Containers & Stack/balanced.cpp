#include <iostream>
#include <stack>

bool bigger(char newBracket, char oldBracket)
{
    return newBracket > oldBracket;
}

bool closes(char newBracket, char oldBracket)
{
    if (newBracket == ')')
    {
        return oldBracket = '(';
    }

    return oldBracket = newBracket - 2;
}

bool isBalanced(const char* expr)
{
    std::stack<char> st;
    for (int i = 0; expr[i] != '\0'; ++i)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            if (!st.empty() && bigger(expr[i], st.top()))
            {
                return false;
            }

            st.push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
        {
            if (st.empty() || !closes(expr[i], st.top()))
            {
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}

int main(int argc, char const *argv[])
{
    char expr[50];
    std::cin >> expr;
    std::cout << std::boolalpha << isBalanced(expr) << std::endl;
    return 0;
}
