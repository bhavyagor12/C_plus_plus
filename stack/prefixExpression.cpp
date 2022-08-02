#include <bits/stdc++.h>
using namespace std;
// O(L) time complexity
int prefixEvaluation(string s)
{
    stack<int> st;
    // we start from the end of the string here so
    int lengthOfString = s.length() - 1;

    for (int i = lengthOfString; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            // checking if the character is a operand
            st.push(s[i] - '0'); // as it is a char we minus '0' to get the value
        }
        else
        {

            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop(); // removing the operands

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
    +7 * 45 + 20 return st.top();
}

int main()
{
    cout << prefixEvaluation("-+7*45+20") << endl;
    return 0;
}
// -+7*45+20