#include <bits/stdc++.h>
using namespace std;

int floorEle(vector<int> &nums, int val)
{
    // floor is the greatest smaller element
    // ciel is the smallest greater element
    // if the val is present in the array than thats the both val;

    int size = nums.size();
    int low = 0, high = size - 1;
    int floor = 0, ceil = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == val)
        {
            return mid;
        }
        else if (nums[mid] < val)
        {
            floor = nums[mid];
            low = mid + 1;
        }
        else
        {
            ceil = nums[mid];
            high = mid - 1;
        }
    }
    return ceil;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    cout << floorEle(nums, 5);
    return 0;
}