#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    int length = s.length();
    stack<char> st;
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {

            st.push(s[i]);
        }
        else if (!st.empty() && s[i] == ')')
        {
            if (st.top() == '(')
            {
                st.pop();
            }
            else
            {
                break;
            }
        }
        else if (!st.empty() && s[i] == ']')
        {
            if (st.top() == '[')
            {
                st.pop();
            }
            else
            {
                break;
            }
        }
        else if (!st.empty() && s[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                break;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
}

int main()
{
    string s = "{([])}";
    if (isValid(s))
    {
        cout << "balanced bracket sequence" << endl;
    }
    else
    {
        cout << "brackets not balanced my boi" << endl;
    }
    return 0;
}