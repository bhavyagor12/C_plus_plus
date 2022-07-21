#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

void permutation(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    // fixing a char
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1); // before i characters + rest of string
        // starting point is compulsory
        permutation(ros, ans + c);
    }
}

int countPath(int starting, int ending)
{
    if (starting == ending)
        return 1;

    if (starting > ending)
    {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += countPath(starting + i, ending);
    }

    return count;
}

int countPathMaze(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
        return 1;

    if (i >= n || j >= n)
        return 0;

    return countPathMaze(n, i + 1, j) + countPathMaze(n, i, j + 1);
}

int tilingProblem(int n)
{
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;

    return tilingProblem(n - 1) + tilingProblem(n - 2);
}

int friendsPairing(int n)
{
    if (n == 0 || n == 1 || n == 2) // 0 zero no ways, 1 person one way stay single, 2 person 2 ways(single both/pair)
    {
        return n;
    }

    return friendsPairing(n - 1) + friendsPairing(n - 2) * (n - 1);
    // case 1(n-1) basically person single
    // case 2(n-2 ) basically person paired with someone
    // pairing possibilities are n -1 hence multiplied
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // permutation("ABC", "");
    // cout << countPath(0, 3) << endl;
    // cout << countPathMaze(3, 0, 0) << endl;
    // cout << tilingProblem(4) << endl;
    cout << friendsPairing(4) << endl;
}