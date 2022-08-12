#include <bits/stdc++.h>
using namespace std;
// n log k // always tell the sorting approach first
int findkthSmallest(vector<int> &nums, int k)
{
    priority_queue<int> maxHeap; // maxHeap in cases of smallest
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        maxHeap.push(nums[i]);
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}
int main()
{
    vector<int> nums = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << findkthSmallest(nums, k);

    return 0;
}