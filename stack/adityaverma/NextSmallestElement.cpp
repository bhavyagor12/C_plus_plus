#include <bits/stdc++.h>
using namespace std;

void nextSmallerElementRight(vector<int> &nums)
{
    int size = nums.size();
    int result[size];
    stack<int> st;

    for (int i = size - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
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

void nextSmallerElementLeft(vector<int> &nums)
{
    int size = nums.size();
    int result[size];
    stack<int> st;

    for (int i = 0; i < size; i++)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
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
    nextSmallerElementRight(nums);
    cout << endl;
    nextSmallerElementLeft(nums);
    return 0;
}
