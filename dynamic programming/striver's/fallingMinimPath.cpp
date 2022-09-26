class Solution
{
private:
    int sumCalc(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        int m = matrix[0].size();

        if (j < 0 || j >= m)
            return 1e8;
        if (i == 0)
            return matrix[0][j];
        if (dp[i][j] != -1)
            return dp[i][j];

        int up = sumCalc(i - 1, j, matrix, dp) + matrix[i][j];
        int leftDiag = sumCalc(i - 1, j - 1, matrix, dp) + matrix[i][j];
        int rightDiag = sumCalc(i - 1, j + 1, matrix, dp) + matrix[i][j];

        int minOfLeftRight = min(leftDiag, rightDiag);

        return dp[i][j] = min(up, minOfLeftRight);
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        // vector<vector<int>> dp(n,vector<int> (m,-1));

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int up = matrix[i][j] + dp[i - 1][j];

                int leftDiag = matrix[i][j];
                if (j - 1 >= 0)
                    leftDiag += dp[i - 1][j - 1];
                else
                    leftDiag += 1e8;

                int rightDiag = matrix[i][j];

                if (j + 1 < m)
                    rightDiag += dp[i - 1][j + 1];
                else
                    rightDiag += 1e8;

                int minOfLeftRight = min(leftDiag, rightDiag);

                dp[i][j] = min(up, minOfLeftRight);
            }
        }

        int minSum = 1e8;
        for (int j = 0; j < m; j++)
        {
            // int ansOFMemo = dp[0][j];
            int ans = dp[n - 1][j];
            minSum = min(minSum, ans);
        }

        return minSum;
    }
};