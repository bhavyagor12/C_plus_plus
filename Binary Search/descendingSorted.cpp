#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &nums, int val)
{
    int size = nums.size();
    int low = 0, high = size - 1;
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
    return -1;
}

int main()
{
    vector<int> nums = {20, 17, 15, 14, 13, 12, 10, 9, 8, 4};
    int valToBeSearch = 15;
    cout << binarySearch(nums, valToBeSearch);

    return 0;
}