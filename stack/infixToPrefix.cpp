#include <bits/stdc++.h>
using namespace std;

int precedenceChecker(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1; // not an operator and return on opening bracket
    }
}

string infixToPrefixConvertor(string s)
{

    reverse(s.begin(), s.end());

    stack<char> st;
    string result;
    int length = s.length();

    for (int i = 0; i < length; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            result += s[i];
        }
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            if (s[i] == '^')
            {
                while (!st.empty() && precedenceChecker(st.top()) >= precedenceChecker(s[i]))
                {
                    result += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && precedenceChecker(st.top()) > precedenceChecker(s[i]))
                {
                    result += st.top();
                    st.pop();
                }
            }

            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    cout << infixToPrefixConvertor("(a-b/c)*(a/k-l)") << endl;
    return 0;
}