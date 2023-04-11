#include <bits/stdc++.h>
using namespace std;
vector<string> isSimilar(vector<string> a, vector<string> b)
{
    vector<string> ans;
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;

    for (int i = 0; i < a.size(); i++)
    {
        string word1 = a[i];
        string word2 = b[i];

        if (word1.length() != word2.length())
        {
            ans.push_back("NO");
        }
        int flag = 1;
        for (int j = 0; j < word1.length(); j++)
        {
            map1[word1[j]]++;
            map2[word2[j]]++;
        }

        for (int j = 0; j < word1.length(); j++)
        {
            if (abs(map1[word1[j]] - map2[word2[j]]) > 3)
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            ans.push_back("YES");
        }
        else
        {
            ans.push_back("NO");
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<string> a(n);
    vector<string> b(n);

    cout << "Enter values for first string array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter values for second string array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<string> ans = isSimilar(a, b);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
