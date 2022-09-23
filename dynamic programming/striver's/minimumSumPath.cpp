class Solution
{
private:
    int explorePaths(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];

        int up = grid[i][j] + explorePaths(i, j - 1, grid, dp);
        int left = grid[i][j] + explorePaths(i - 1, j, grid, dp);

        return dp[i][j] = min(up, left);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        int dp[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[0][0];
                else
                {
                    int up = 1e9;
                    int left = 1e9;
                    if (i > 0)
                        up = grid[i][j] + dp[i - 1][j];
                    if (j > 0)
                        left = grid[i][j] + dp[i][j - 1];
                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};