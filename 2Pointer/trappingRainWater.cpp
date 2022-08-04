#include <bits/stdc++.h>
using namespace std;

// time -o(n) space - o(1)
// less optimal is prefixMax and suffixMax uska i pe min - heights[i]; o(n) and o(2n) space
int get_trappedWater(vector<int> &heights)
{
    int size = heights.size();
    int left = 0;
    int right = size - 1;
    int leftMax = 0, rightMax = 0;
    int res = 0;
    // init done

    while (left <= right)
    {
        // stop when left crosses right
        // doing a step also when left = right

        if (heights[left] <= heights[right])
        {
            if (heights[left] >= leftMax)
            {
                leftMax = heights[left];
            }
            else
            {
                res += leftMax - heights[left];
            }
            left++;
        }
        else
        {
            if (heights[right] >= rightMax)
            {
                rightMax = heights[right];
            }
            else
            {
                res += rightMax - heights[right];
            }
            right--;
        }
    }
    return res;
}

int main()
{

    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << get_trappedWater(heights) << endl;

    return 0;
}