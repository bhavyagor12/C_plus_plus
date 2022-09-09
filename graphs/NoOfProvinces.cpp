class Solution
{
private:
    void dfs(int node, vector<int> adjList[], int visited[])
    {
        visited[node] = 1;
        for (auto it : adjList[node])
        {
            if (!visited[it])
            {
                dfs(it, adjList, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        vector<int> adjList[V + 1];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        } // list is ready

        int visited[V + 1];
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
        } // initializing to 0;

        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adjList, visited); // for varied starting nodes
                count++;
            }
        }
        return count;
    }
};