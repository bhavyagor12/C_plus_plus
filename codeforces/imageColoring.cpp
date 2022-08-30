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
    int t;
    cin >> t;
    while (t--)
    {
        char arr[4];
        map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 4; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < 4; i++)
        {
            mp[arr[i]]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            pq.push({it->second, it->first});
        }
        while (!pq.empty())
        {
            if (pq.top().first == 4)
            {
                cout << "0" << endl;
                break;
            }
            else if (pq.top().first == 3)
            {
                cout << "1" << endl;
                break;
            }
            else if (pq.top().first == 2)
            {
                pq.pop();
                if (pq.top().first == 1)
                {
                    cout << "2" << endl;
                    break;
                }
                else
                {
                    cout << "1" << endl;
                    break;
                }
            }
            else
            {
                cout << "3" << endl;
                break;
            }
            pq.pop();
        }
    }
}