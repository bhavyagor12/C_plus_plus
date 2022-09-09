class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid, int delta_row[], int delta_col[])
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverse the neighbours
            for (int i = 0; i < 4; i++)
            {
                int neighbour_row = row + delta_row[i];
                int neighbour_col = col + delta_col[i];

                if (neighbour_row >= 0 && neighbour_row < n && neighbour_col >= 0 && neighbour_col < m)
                {
                    if (grid[neighbour_row][neighbour_col] == '1' && !visited[neighbour_row][neighbour_col])
                    {
                        visited[neighbour_row][neighbour_col] = 1;
                        q.push({neighbour_row, neighbour_col});
                    }
                }
            }
        }
    }

    void dfs(int row, int col, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (row < 0 || row == n || col < 0 || col == m || grid[row][col] == '0')
        {
            return;
        }
        grid[row][col] = '0';
        dfs(row + 1, col, grid);
        dfs(row - 1, col, grid);
        dfs(row, col - 1, grid);
        dfs(row, col + 1, grid);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        //        vector<vector<int>> visited(n,vector<int>(m,0));

        int cnt = 0;

        //         int delta_row[] = {-1,0,1,0};
        //         int delta_col[] = {0,1,0,-1};
        //         for(int row = 0; row < n;row++){
        //             for(int col = 0; col < m; col++){
        //                 if(!visited[row][col] && grid[row][col] == '1'){
        //                     cnt++;
        //                     bfs(row,col,visited,grid,delta_row,delta_col);
        //                 }
        //             }
        //         }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }

        return cnt;
    }
};