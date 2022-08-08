#include <bits/stdc++.h>
using namespace std;

int maxHistogram(vector<int> &heights)
{
    int size = heights.size();
    int rightSmall[size], leftSmall[size], result = INT_MIN;
    stack<int> st;

    for (int i = 0; i < size; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
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
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            rightSmall[i] = 7;
        }
        else
        {
            rightSmall[i] = st.top();
        }
        st.push(i);
    }

    // for (int i = 0; i < size; i++)
    // {
    //     cout << result[i] << " "; // for displaying all the results
    // }

    for (int i = 0; i < size; i++)
    {
        result = max(result, (rightSmall[i] - leftSmall[i] - 1) * heights[i]);
    }

    return result;
}

int main()
{
    vector<int> heights = {6, 2, 5, 4, 5, 1, 6};
    cout << maxHistogram(heights) << endl;
    return 0;
}