class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int, int>, int>> q; // {1,1},0 denoting row,col and dist
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    // starting point of our bfs as we start from 0's
                    q.push({{i, j}, 0});
                    vis[i][j] = 1; // push into queue and mark as visited
                }
                else
                {
                    vis[i][j] = 0; // all other nodes are non visited
                }
            }
        }

        int delta_row[] = {-1, 0, +1, 0}; // directions
        int delta_col[] = {0, +1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;

            // now we travel in all four directions

            for (int i = 0; i < 4; i++)
            {
                int neighbour_row = row + delta_row[i];
                int neighbour_col = col + delta_col[i];

                if (neighbour_row >= 0 && neighbour_row < n && neighbour_col >= 0 && neighbour_col < m)
                {
                    if (!vis[neighbour_row][neighbour_col])
                    {
                        vis[neighbour_row][neighbour_col] = 1;
                        q.push({{neighbour_row, neighbour_col}, steps + 1});
                    }
                }
            }
        }

        return dist;
    }
};