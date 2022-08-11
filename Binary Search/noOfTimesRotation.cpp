#include <bits/stdc++.h>
using namespace std;

int countRotations(vector<int> &nums)
{
    int size = nums.size();
    int low = 0, high = size - 1;
    int prev, next = 0;
    if (nums[low] <= nums[high])
    {
        // this means that the array is in sorted order
        return 0; // same condition is also done inside the while loop
    }
    else
    {
        while (low <= high)
        {
            if (nums[low] <= nums[high])
            {
                return low;
            }
            int mid = low + (high - low) / 2;
            prev = (mid + size - 1) % size; // bound it to the array
            next = (mid + 1) % size;
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
            {
                return mid;
            }
            else if (nums[low] <= nums[mid])
            {
                low = mid + 1;
            }
            else if (nums[mid] <= nums[high])
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {3, 3, 3, 1};
    cout << countRotations(nums) << endl;
    // logic is the idx of the min ele is the amount of rotations

    return 0;
}