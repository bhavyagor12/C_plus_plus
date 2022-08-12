// question to print k elements (largest)
#include <bits/stdc++.h>
using namespace std;
void printKthLargest(vector<int> &nums, int k) // as largest word -- use min Heap
// always vice versa
{
    priority_queue<int, vector<int>, greater<int>> minHeap; // min Heap declaration
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        minHeap.push(nums[i]);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}
int main()
{
    vector<int> nums = {7, 10, 4, 3, 20, 15};
    int k = 3;
    printKthLargest(nums, k);
}
