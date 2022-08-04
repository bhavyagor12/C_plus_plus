#include <bits/stdc++.h>
using namespace std;
// brute for(int i = 0;i<n;i++) for(int j = i+1;j <n; j++)
//  as j is dependant we move to stacks

void nextGreaterElementRight(vector<int> &nums)
{
    int size = nums.size();
    stack<int> st;
    int result[size];
    for (int i = size - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        if (st.empty())
            result[i] = -1;
        else
        {
            result[i] = nums[st.top()];
        }
        st.push(i);
    }
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
}

void nextGreaterElementLeft(vector<int> &nums)
{
    int size = nums.size();
    int result[size];
    stack<int> st;

    for (int i = 0; i < size; i++)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        if (st.empty())
            result[i] = -1;
        else
        {
            result[i] = nums[st.top()];
        }

        st.push(i);
    }
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
}
int main()
{
    vector<int> nums = {1, 3, 2, 4};
    nextGreaterElementRight(nums);
    cout << endl;
    nextGreaterElementLeft(nums);

    return 0;
}