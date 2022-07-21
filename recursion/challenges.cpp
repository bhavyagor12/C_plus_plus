#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

bool sorted(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }

    bool restArray = sorted(arr + 1, n - 1);
    return (arr[0] < arr[1] && restArray);
}

void dec(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    dec(n - 1);
}
void inc(int n)
{
    if (n == 0)
        return;
    inc(n - 1);
    cout << n << endl;
}
int first_occurence(int arr[], int n, int i, int key)
{
    if (i == n)
        return -1;

    if (arr[i] == key)
        return i;
    return first_occurence(arr, n, i + 1, key);
}
int last_occurence(int arr[], int n, int i, int key)
{
    if (i == n)
        return -1;

    int restArray = last_occurence(arr, n, i + 1, key);
    if (restArray != -1)
    {
        return restArray;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}

string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string code = keypadArr[ch - '0'];
    string ros = s.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, ans + code[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // int n;

    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // cout << sorted(arr, n) << endl;
    // dec(n);
    // inc(n);
    // cout << first_occurence(arr, n, 0, 2) << endl;
    // cout << last_occurence(arr, n, 0, 2);

    keypad("23", "");
}