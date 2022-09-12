class Solution
{
    bool check(int node, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<int> q;
        color[node] = 0;
        q.push(node);

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            for (int adj : graph[temp])
            {

                if (color[adj] == -1)
                {
                    color[adj] = !color[temp];
                    q.push(adj);
                }
                else if (color[adj] == color[temp])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(int node, int initialColor, vector<vector<int>> &graph, vector<int> &color)
    {

        color[node] = initialColor;

        for (auto adj : graph[node])
        {
            if (color[adj] == -1)
            {
                if (dfs(adj, 1 - initialColor, graph, color) == false)
                {
                    return false;
                }
            }
            else if (color[adj] == initialColor)
            {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                // if(check(i,graph,color) == false){
                //  return false;
                if (dfs(i, 0, graph, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};