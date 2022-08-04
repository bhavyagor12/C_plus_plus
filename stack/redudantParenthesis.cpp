#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool ans = false;
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                ans = true;
            }
            while (!st.empty() && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'))
            {
                cout << st.top() << endl;
                st.pop();
            }
            st.pop();
        }
    }
    cout << ans << endl;
    return 0;
}