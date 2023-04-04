#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int findCircleNum(int[][] M)
{
    int N = M.length;
    boolean[] visited = new boolean[N];
    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        if (!visited[i])
        {
            dfs(M, visited, i);
            ++result;
        }
    }
    return result;
}

void dfs(int[][] M, boolean[] visited, int cur)
{
    if (visited[cur])
        return;
    visited[cur] = true;
    for (int i = 0; i < M.length; ++i)
    {
        if (M[cur][i] == 1)
            dfs(M, visited, i);
    }
}

// Union find
int result;

int findCircleNumII(int[][] M)
{
    int N = M.length;
    int[] parent = new int[N];
    this.result = N;
    for (int i = 0; i < N; ++i)
        parent[i] = i;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (M[i][j] == 1)
                union(parent, i, j);
        }
    }
    return this.result;
}

// void union(int[] parent, int i, int j)
// {
//     int iroot = find(parent, i);
//     int jroot = find(parent, j);
//     if (iroot != jroot)
//     {
//         parent[jroot] = iroot;
//         --this.result;
//     }
// }

// int find(int[] parent, int i)
// {
//     if (parent[i] == i)
//         return i;
//     int r = find(parent, parent[i]);
//     parent[i] = r; // compress
//     return r;
// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    int m;
    cin >> n >> m;
    int arr[100][100];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << findCircleNum(arr);
    return 0;
}