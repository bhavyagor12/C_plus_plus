#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

vector<int> dijkstraAlgo(int V, vector<vector<int>> adj[], int S)
{
    // min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V);
    for (int i = 0; i < V; i++)
    {
        dist[i] = 1e9;
    }
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int edgeWeight = it[1];
            int adjNode = it[0];

            // got better distance
            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;
                // now pq needs to push
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif

    int n, m, S;
    cin >> n >> m >> S;
    // m is edges n is nodes
    vector<vector<int>> adjList[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> temp1, temp2;
        temp1.push_back(v);
        temp1.push_back(w);
        adjList[u].push_back(temp1);
        temp2.push_back(u);
        temp2.push_back(w);
        // remove this line when it is directed graph and space complexity is O(E);
        adjList[v].push_back(temp2);
    }
    vector ans = dijkstraAlgo(n, adjList, S);

    for (auto it : ans)
    {
        cout << it << " ";
    }
}