#include <bits/stdc++.h>
using namespace std;

int countOccurence(vector<int> nums, int val)
{
    int size = nums.size();
    int low = 0, high = size - 1;
    int firstIdx = -1, lastIdx = -1;
    int count = 0;

    // first occurence
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == val)
        {
            firstIdx = mid;
            high = mid - 1;
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
    low = 0, high = size - 1;
    // last occurence
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == val)
        {
            lastIdx = mid;
            low = mid + 1;
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

    count = (lastIdx - firstIdx) + 1;
    return count;
}

int main()
{
    vector<int> nums = {2, 4, 10, 10, 10, 18, 20};
    cout << countOccurence(nums, 10) << endl;

    return 0;
}