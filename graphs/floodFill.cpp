class Solution
{
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int initColor, int color, int delta_row[], int delta_col[])
    {
        int n = image.size();
        int m = image[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m || ans[row][col] != initColor || ans[row][col] == color)
        {
            return;
        }

        // not considered as ideal code readibilty
        // dfs(row + 1, col, ans, image, initColor, color);
        // dfs(row - 1, col, ans, image, initColor, color);
        // dfs(row, col + 1, ans, image, initColor, color);
        // dfs(row, col - 1, ans, image, initColor, color);
        ans[row][col] = color;
        // ideal way
        for (int i = 0; i < 4; i++)
        {
            int neighbour_row = row + delta_row[i];
            int neighbour_col = col + delta_col[i];

            dfs(neighbour_row, neighbour_col, ans, image, initColor, color, delta_row, delta_col);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        vector<vector<int>> ans = image;
        int initColor = image[sr][sc];
        dfs(sr, sc, ans, image, initColor, color, delta_row, delta_col);
        //         queue<pair<int,int>> q;
        //         q.push({sr,sc});
        //         ans[sr][sc] = color;

        //         while(!q.empty()){
        //             int row = q.front().first;
        //             int col = q.front().second;
        //             q.pop();

        //             for(int i = 0;i < 4;i++){
        //                 int neighbour_row = row + delta_row[i];
        //                 int neighbour_col = col + delta_col[i];

        //                 if(neighbour_row <0 || neighbour_row >=n || neighbour_col <0 || neighbour_col >= m ||
        //                   ans[neighbour_row][neighbour_col] != initColor ||
        //                    ans[neighbour_row][neighbour_col] == color){
        //                     //if its out of boundary || if it is not initialized color || if it is already new color
        //                 continue;
        //                 }
        //                ans[neighbour_row][neighbour_col] = color;
        //                q.push({neighbour_row,neighbour_col});
        //             }
        //         }

        return ans;
    }
};