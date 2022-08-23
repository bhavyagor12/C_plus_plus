#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j)
{
    // here 3 parameters are pattern
    // array and string can be the two inputs

    if (i > j) // can be (i>=j) or(i<j)
        return 0;
    // base condition changes according to question
    // think here for the invalid input case
    int ans = INT_MAX; // can be INT_MIN also
    for (int k = i; k < j; k++)
    {
        // k can be i+1 -- to k<=j-1
        // minor changes

        int temp_ans = solve(arr, i, k) + solve(arr, k + 1, j); // plus can be minus also
        ans = min(ans, temp_ans);                               // can be max also
    }

    return ans;
}
