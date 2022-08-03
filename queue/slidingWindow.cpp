#include <bits/stdc++.h>
using namespace std;

int main()
{
    // given an array and a k representing the window size
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    // using multiset n log n
    // multiset<int, greater<int>> s;
    // vector<int> ans;

    // for (int i = 0; i < k; i++)
    // {
    //     s.insert(a[i]);
    // }
    // ans.push_back(*s.begin());
    // for (int i = k; i < n; i++)
    // {
    //     s.erase(s.lower_bound(a[i - k])); // removing the value that sliding window now ignores //
    //     s.insert(a[i]);
    //     ans.push_back(*s.begin());
    // }

    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }

    deque<int> q;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        // make sure deque is always in non increasing order meaning first element is always the greatest

        while (!q.empty() && a[q.back()] < a[i])
        {
            // array element is bigger so we have to pop back
            q.pop_back();
        }
        q.push_back(i); // pushing the index here
    }                   // first window ans should be here
    ans.push_back(a[q.front()]);
    for (int i = k; i < n; i++)
    {
        if (q.front() == i - k)
        { // current window has moved so here we have to remove
            q.pop_front();
        }
        while (!q.empty() && a[q.back()] < a[i])
        {
            // array element is bigger so we have to pop back
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}