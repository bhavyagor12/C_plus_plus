// dfs fails in one test case and the error is weird check later

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int delta_row[], int delta_col[])
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int neighbour_row = row + delta_row[i];
            int neighbour_col = col + delta_col[i];

            if (neighbour_row >= 0 && neighbour_row < n && neighbour_col >= 0 && neighbour_col < m)
            {
                if (!vis[neighbour_row][neighbour_col] && grid[neighbour_row][neighbour_col] == 1)
                {
                    dfs(neighbour_row, neighbour_col, vis, grid, delta_row, delta_col);
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};

        // first row && last row
        //       for(int col = 0; col < m;col++){
        //           if(!vis[0][col] && grid[0][col] == 1){
        //               dfs(0,col,vis,grid,delta_row,delta_col);
        //           }
        //           if(!vis[n-1][col] && grid[0][col] == 1){
        //               dfs(n-1,col,vis,grid,delta_row,delta_col);
        //           }
        //       }

        //       //first col && last col
        //       for(int row = 0; row < n;row++){
        //        if(!vis[row][0]  && grid[row][0] == 1){
        //            dfs(row,0,vis,grid,delta_row,delta_col);
        //        }
        //        if(!vis[row][m-1] && grid[row][m-1] == 1){
        //            dfs(row,m-1,vis,grid,delta_row,delta_col);
        //        }
        //       }

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                    if (grid[i][j] == 1 && !vis[i][j])
                    {
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int n_row = row + delta_row[i];
                int n_col = col + delta_col[i];

                if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m)
                {
                    if (grid[n_row][n_col] == 1 && !vis[n_row][n_col])
                    {
                        q.push({n_row, n_col});
                        vis[n_row][n_col] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};