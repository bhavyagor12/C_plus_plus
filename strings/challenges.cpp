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

    string str;
    cin >> str;

    // manually
    //  for (int i = 0; i < str.size(); i++)
    //  {
    //      // convert upper
    //      if (str[i] >= 'a' && str[i] <= 'z')
    //      {
    //          str[i] = str[i] - 32;
    //      }
    //      // convert lower
    //      if (str[i] >= 'A' && str[i] <= 'Z')
    //      {
    //          str[i] = str[i] + 32;
    //          break;
    //      }
    //  }

    // using transform upper
    // transform(str.begin(), str.end(), str.begin(), ::toupper);
    // cout << str << endl;
    // // lower
    // transform(str.begin(), str.end(), str.begin(), ::tolower);
    // cout << str << endl;

    // biggest number from numberic string
    sort(str.begin(), str.end(), greater<int>()); // descending order
    int number = stoi(str);
    cout << number << endl;
}