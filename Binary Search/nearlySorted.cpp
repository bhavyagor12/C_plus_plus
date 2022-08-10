#include <bits/stdc++.h>
using namespace std;

int binaryNearlySorted(vector<int> &nums, int val)
{
    int size = nums.size();
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == val)
        {
            return mid;
        }
        if (mid - 1 >= low && nums[mid - 1] == val)
        {
            return mid - 1;
        }
        if (mid + 1 <= high && nums[mid + 1] == val)
        {
            return mid + 1;
        }
        else if (nums[mid] < val)
        {
            low = mid + 2;
        }
        else
        {
            high = mid - 2;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {5, 10, 30, 20, 40};
    cout << binaryNearlySorted(nums, 20);
    return 0;
}