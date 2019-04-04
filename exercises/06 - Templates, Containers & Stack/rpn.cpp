#include <iostream>
#include <stack>

double rpnEval(const char* expr)
{
    std::stack<double> st;
    double op1, op2;

    for (int i = 0 ; expr[i] != '\0'; ++i)
    {
        if (expr[i] >= '0' && expr[i] <= '9')
        {
            st.push(expr[i] - '0');
        }

        else
        {
            // Assume correct expression, so there are at least 2 elements in the stack
            // Note the order
            op2 = st.top();
            st.pop();
            op1 = st.top();
            switch (expr[i])
            {
                case '+':
                    st.top() = op1 + op2;
                    break;
                case '-':
                    st.top() = op1 - op2;
                    break;
                case '*':
                    st.top() = op1 * op2;
                    break;
                case '/':
                    // Assume correct, so op2 != 0
                    st.top() = op1 / op2;
                    break;
            }
        }
    }

    return st.top();
}

int main()
{
    char expr[50];
    std::cin >> expr;
    std::cout << rpnEval(expr) << std::endl;
    return 0;
}
