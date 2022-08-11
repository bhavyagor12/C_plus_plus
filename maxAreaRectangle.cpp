#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int maxAreaHisto(vector<int> v, int arr[], int n)
{
    vector<int> left;
    stack<pair<int, int>> s;
    int pseudoindex1 = -1;
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            left.push_back(pseudoindex1);
        }
        else if (s.size() > 0 && s.top().first < arr[i])
        {
            left.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                left.push_back(pseudoindex1);
            }
            else
            {
                left.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }

    while (!s.empty())
    {
        s.pop();
    }

    vector<int> right;
    // stack <int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            right.push_back(n);
        }
        else if (s.size() > 0 && s.top().first < arr[i])
        {
            right.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                right.push_back(n);
            }
            else
            {
                right.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    reverse(right.begin(), right.end());

    int width[n];
    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
    }
    int area[n];
    for (int i = 0; i < n; i++)
    {
        area[i] = arr[i] * width[i];
    }
    int maxarea = 0;
    for (int i = 0; i < n; i++)
    {
        maxarea = max(maxarea, area[i]);
    }
    // cout << maxarea;
    return maxarea;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> v;
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int maxarea = 0;
    for (int j = 0; j < n; j++)
    {
        v.push_back(arr[0][j]);
    }
    maxarea = maxAreaHisto(v, arr[0], n);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                v[j] = 0;
            }
            else
            {
                v[j] = v[j] + arr[i][j];
            }
        }
        maxarea = max(maxarea, maxAreaHisto(v, arr[i], n));
        // cout<<maxarea<<endl;
    }
    cout << maxarea << endl;
}

// max area of rectangle in a binary matrix