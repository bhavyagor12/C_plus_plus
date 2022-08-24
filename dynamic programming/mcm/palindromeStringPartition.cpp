#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string s, int i, int j)
{
    if (i >= j || isPalindrome(s, i, j))
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp_ans = solve(s, i, k) + solve(s, k + 1, j) + 1;
        ans = min(ans, temp_ans);
    }
    return ans;
}

/// leetcode palidrome partitioning II
// class Solution {
// private:
//     bool isPalindrome(string &s,int i,int j){
//         if(i > j || i == j) return true;
//         while(i<j){
//             if(s[i] != s[j]){
//                   return false;
//             }
//                 i++;
//                 j--;
//             }
//          return true;
//     }
//     int solveCuts(string &s,int i,int j){
//         if(i>=j){
//             return 0;
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         if(isPalindrome(s,i,j)){
//             return dp[i][j] = 0;
//         }
//         int ans = INT_MAX;
//         for(int k = i;k<j;k++){
//              if(isPalindrome(s, i, k)){
//                 int temp_ans = solveCuts(s, k+1, j) + 1;
//                 ans = min (ans, temp_ans);
//             }
//         }
//         return dp[i][j] = ans;
//     }
// };
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    cout << solve(s, 0, n - 1);
    return 0;
}