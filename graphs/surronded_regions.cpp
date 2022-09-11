class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int delta_row[], int delta_col[])
    {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int neighbour_row = row + delta_row[i];
            int neighbour_col = col + delta_col[i];

            if (neighbour_row >= 0 && neighbour_row < n && neighbour_col >= 0 && neighbour_col < m)
            {
                if (!vis[neighbour_row][neighbour_col] && board[neighbour_row][neighbour_col] == 'O')
                {
                    vis[neighbour_row][neighbour_col] = 1;
                    dfs(neighbour_row, neighbour_col, vis, board, delta_row, delta_col);
                }
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        // traverse first row,last row
        for (int col = 0; col < m; col++)
        {
            if (!vis[0][col] && board[0][col] == 'O')
            {
                vis[0][col] = 1;
                dfs(0, col, vis, board, delta_row, delta_col);
            }

            if (!vis[n - 1][col] && board[n - 1][col] == 'O')
            {
                vis[n - 1][col] = 1;
                dfs(n - 1, col, vis, board, delta_row, delta_col);
            }
        }

        // first and last col
        for (int row = 0; row < n; row++)
        {
            if (!vis[row][0] && board[row][0] == 'O')
            {
                vis[row][0] = 1;
                dfs(row, 0, vis, board, delta_row, delta_col);
            }

            if (!vis[row][m - 1] && board[row][m - 1] == 'O')
            {
                vis[row][m - 1] = 1;
                dfs(row, m - 1, vis, board, delta_row, delta_col);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};