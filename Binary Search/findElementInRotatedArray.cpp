#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &nums, int start, int end, int val)
{
    int size = nums.size();
    if (size == 1 && nums[0] == val)
    {
        return 0;
    }
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == val)
        {
            return mid;
        }
        else if (nums[mid] < val)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int findMinElement(vector<int> &nums)
{
    // the index of the min ele
    int size = nums.size();
    int start = 0, end = size - 1;

    int prev = 0, next = 0;

    // cout << val << endl;
    while (start <= end)
    {
        if (nums[start] <= nums[end])
        {
            return start;
        }
        int mid = start + (end - start) / 2;
        prev = (mid - 1 + size) % size;
        next = (mid + 1) % size;
        if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
        {
            return mid;
        }
        else if (nums[start] <= nums[mid])
        {
            start = mid + 1;
        }
        else if (nums[mid] <= nums[end])
        {
            end = end - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {11, 12, 15, 18, 2, 5, 6, 8};
    int size = nums.size();
    int minEle = findMinElement(nums);
    if (binarySearch(nums, 0, minEle - 1, 9) != -1)
    {
        cout << binarySearch(nums, 0, minEle - 1, 9) << endl;
    }
    else if (binarySearch(nums, minEle, size - 1, 9) != -1)
    {
        cout << binarySearch(nums, minEle, size - 1, 9) << endl;
    }
    else
    {
        cout << -1;
    }
    return 0;
}