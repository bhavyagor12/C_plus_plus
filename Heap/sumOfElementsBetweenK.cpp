#include <bits/stdc++.h>
using namespace std;
int findKthSmallest(vector<int> &nums, int k)
{
    int size = nums.size();
    priority_queue<int> maxHeap;
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

    vector<int> nums = {1, 3, 12, 5, 15, 11};
    int firstK = findKthSmallest(nums, 3);
    int secondK = findKthSmallest(nums, 6);
    int sum = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > firstK && nums[i] < secondK)
        {
            sum += nums[i];
        }
    }

    cout << sum << endl;
}