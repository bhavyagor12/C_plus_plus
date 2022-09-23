class Solution
{
private:
    int triangleCalc(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        int n = triangle.size();

        if (i == n - 1)
            return triangle[n - 1][j];
        if (i >= n)
            return INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = triangleCalc(i + 1, j, triangle, dp) + triangle[i][j];
        int diagonal = triangleCalc(i + 1, j + 1, triangle, dp) + triangle[i][j];

        return dp[i][j] = min(down, diagonal);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        // vector<vector<int>> dp(n,vector<int> (n, -1));
        // return triangleCalc(0,0,triangle,dp);

        // vector<vector<int>> dp(n,vector<int> (n, 0));
        vector<int> front(n, 0), curr(n, 0);
        for (int j = 0; j < n; j++)
            front[j] = triangle[n - 1][j];

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j + 1];
                curr[j] = min(down, diag);
            }
            front = curr;
        }

        return front[0];
    }
};