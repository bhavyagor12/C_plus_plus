#include <bits/stdc++.h>
using namespace std;
int MaxAreaHisto(vector<int> &mattrix)
{
    int size = mattrix.size();
    int rightSmall[size], leftSmall[size];
    int result = INT_MIN;
    stack<int> st;
    for (int i = 0; i < size; i++)
    {
        while (!st.empty() && mattrix[st.top()] >= mattrix[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            leftSmall[i] = -1;
        }
        else
        {
            leftSmall[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        // empty the stack
        st.pop();
    }

    for (int i = size - 1; i >= 0; i--)
    {
        while (!st.empty() && mattrix[st.top()] >= mattrix[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            rightSmall[i] = size;
        }
        else
        {
            rightSmall[i] = st.top();
        }
        st.push(i);
    }
    for (int i = 0; i < size; i++)
    {
        result = max(result, (rightSmall[i] - leftSmall[i] - 1) * mattrix[i]);
    }

    return result;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<int> mattrix;
    for (int j = 0; j < m; j++)
    {
        mattrix.push_back(arr[0][j]);
    }
    mx = MaxAreaHisto(mattrix);
    cout << mx << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                mattrix[j] = 0;
            }
            else
            {
                mattrix[j] = mattrix[j] + arr[i][j];
            }
        }
        mx = max(mx, MaxAreaHisto(mattrix));
    }
    cout << mx << " ";

    return 0;
}