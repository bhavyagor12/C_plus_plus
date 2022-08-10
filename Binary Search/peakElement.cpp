#include <bits/stdc++.h>
using namespace std;

int findPeak(vector<int> &nums)
{
    int size = nums.size();
    // int peak = 0;
    int low = 0, high = size - 1;
    int prev = 0, next = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        prev = mid - 1;
        next = mid + 1;
        if (mid == 0 && nums[mid] > nums[prev])
        {
            return low;
        }
        if (mid == size - 1 && nums[mid] > nums[high])
        {
            return high;
        }
        else if (nums[mid] > nums[prev] && nums[mid] > nums[next])
        {
            return mid;
        }
        else if (nums[mid] < nums[prev])
        {
            high = mid - 1;
        }
        else if (nums[mid] < nums[next])
        {
            low = mid + 1;
        }
    }
}

int main()
{
    vector<int> nums = {10, 20, 30, 40, 50};
    cout << findPeak(nums) << endl;

    return 0;
}