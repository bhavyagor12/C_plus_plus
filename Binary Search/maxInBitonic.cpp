#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &nums)
{
    int size = nums.size();
    int low = 0, high = size - 1;
    int prev = 0, next = 0;
    int mid = 0;
    if (size == 1)
    {
        return 0;
    }
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        prev = mid - 1;
        next = mid + 1;
        if (mid == 0 && nums[mid] > nums[next])
        {
            return low;
        }
        if (mid == size - 1 && nums[mid] > nums[prev])
        {
            return high;
        }

        else if (mid != 0 && mid != size - 1 && nums[mid] > nums[prev] && nums[mid] > nums[next])
        {
            return mid;
        }
        else if (mid != 0 && nums[mid] < nums[prev])
        {
            high = mid - 1;
        }
        else if (mid != size - 1 && nums[mid] < nums[next])
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 3, 8, 12, 4, 2};
    cout << findMax(nums) << endl;

    return 0;
}