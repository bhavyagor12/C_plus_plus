// can we solved using finding floor and ceil too

#include <bits/stdc++.h>
using namespace std;

int minDifference(vector<int> &nums, int val)
{
    int size = nums.size();
    int low = 0, high = size - 1;
    int minDiff1 = 0, minDiff2 = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == val)
        {
            return val;
        }
        else if (nums[mid] < val)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // here as there is no key we know the
    //  low and high pointer have crossed each other
    //  hence we also know they always point to their neighbours
    minDiff1 = abs(nums[low] - val);
    minDiff2 = abs(nums[high] - val);
    if (minDiff1 < minDiff2)
    {
        return nums[low];
    }
    else
    {
        return nums[high];
    }
}

int floorCeil(vector<int> nums, int val)
{
    int floor = 0, ceil = 0;
    int size = nums.size();
    int low = 0, high = size - 1;
    int minDiff1 = 0, minDiff2 = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == val)
        {
            floor = nums[mid];
            ceil = nums[mid];
        }
        else if (nums[mid] < val)
        {
            floor = nums[mid];
            low = mid + 1;
        }
        else
        {
            ceil = nums[mid];
            high = high - 1;
        }
    }
    minDiff1 = abs(ceil - val);
    minDiff2 = abs(floor - val);
    if (minDiff1 < minDiff2)
    {
        return ceil;
    }
    else
    {
        return floor;
    }
}
int main()
{
    vector<int> nums = {1, 3, 8, 10, 15};
    // cout << floorCeil(nums, 12) << endl;
    cout << minDifference(nums, 12) << endl;
    return 0;
}