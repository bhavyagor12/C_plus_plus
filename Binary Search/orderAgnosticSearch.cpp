#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &nums, int val)
{
    int size = nums.size();
    int low = 0, high = size - 1;
    if (size == 1 && nums[0] == val)
    {
        return 0;
    }
    if (nums[low] < nums[high]) // ascending binary search
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // less optimised//(low + high) / 2; //can cause overflow
            if (nums[mid] == val)
            {
                return mid;
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
    }
    else // descending binary search
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // less optimised//(low + high) / 2; //can cause overflow
            if (nums[mid] == val)
            {
                return mid;
            }
            else if (nums[mid] > val)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {20, 17, 15, 14, 13, 12, 10, 9, 8, 4};
    int valToBeSearch = 20;
    cout << binarySearch(nums, valToBeSearch);

    return 0;
}