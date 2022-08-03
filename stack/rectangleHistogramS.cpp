#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int size = heights.size();
    stack<int> st;
    int leftSmall[size], rightSmall[size];

    for (int i = 0; i < size; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            leftSmall[i] = 0;
        }
        else
        {
            leftSmall[i] = st.top() + 1;
        }

        st.push(i);
    }
    while (!st.empty())
        st.pop();
    // clear the stack and reuse the stack for left small

    for (int i = size - 1; i >= 0; i--)
    {
        while (!st.empty() and heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            rightSmall[i] = size - 1;
        }
        else
        {
            rightSmall[i] = st.top() - 1;
        }
        st.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < size; i++)
    {
        maxArea = max(maxArea, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
    }

    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}