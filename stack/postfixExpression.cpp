#include <bits/stdc++.h>
using namespace std;
// O(L) time complexity
int postfixEvaluation(string s)
{
    stack<int> st;
    int length = s.length();

    for (int i = 0; i < length; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    cout << postfixEvaluation("46+2/5*7+") << endl;
    return 0;
}