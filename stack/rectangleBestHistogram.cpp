#include <bits/stdc++.h>
using namespace std;

int rectangleLargest(vector<int> &heights)
{
    int size = heights.size();
    int maxArea = 0;
    stack<int> st;
    for (int i = 0; i <= size; i++)
    {
        // as we have to go till the last location with 0;
        while (!st.empty() && (i == size || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
            {
                width = i;
            }
            else
            {
                width = i - st.top() - 1;
            }
            maxArea = max(maxArea, width * height);
        }
        st.push(i);
    }
    return maxArea;
}
int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << rectangleLargest(heights) << endl;
    return 0;
}