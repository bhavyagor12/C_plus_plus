#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    // this is the adj matrix way
    // int adjMatrix[n + 1][m + 1]; // if one based indexing
    // // if zero based then [n][m] work
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adjMatrix[u][v] = 1;
    //     adjMatrix[v][u] = 1;
    // }
    // TC -- O(N) SC -- O(n*m);

    // adj list way using an array
    vector<int> adjList[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        // remove this line when it is directed graph and space complexity is O(E);
        adjList[v].push_back(u);
    }

    for (int i = 0; i < m; i++)
    {
        cout << i << "->";
        for (int &x : adjList[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}