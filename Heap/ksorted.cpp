// given nearly sorted array or k sorted array
#include <bits/stdc++.h>
using namespace std;
vector<int> sortK(vector<int> &nums, int k)
{
    vector<int> ans;
    int size = nums.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < size; i++)
    {
        minHeap.push(nums[i]);
        if (minHeap.size() > k)
        {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    while (!minHeap.empty())
    {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }

    return ans;
}
int main()
{
    vector<int> nums = {7, 10, 4, 3, 20, 15};
    int k = 3;
    vector<int> ans = sortK(nums, k);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}