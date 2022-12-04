#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "WWMMMWMWWWMMMMWWWWWMMWMMWWW";
    stack<char> st;
    int count = 0, output = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (!st.empty())
        {
            if (str[i] == 'W')
                st.push('W');

            if (st.top() == 'W' && str[i] == 'M')
            {
                count++;
                st.pop();
            }
        }

        if (st.empty())
        {
            output = max(output, count * 2);
            count = 0;
        }

        if (str[i] == 'W')
            st.push('W');
    }

    cout << output;
    return 0;
}