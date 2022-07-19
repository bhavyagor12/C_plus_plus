#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

void reverse(string str)
{
    if (str.length() == 0)
        return;
    string ros = str.substr(1); // 1 ke baad ke elements
    reverse(ros);
    cout << str[0];
}

void replacePi(string str)
{
    if (str.length() == 0)
        return;

    if (str[0] == 'p' && str[1] == 'i')
    {
        cout << 3.14;
        replacePi(str.substr(2));
        // because we replaced first 2 already thats why
    }
    else
    {
        cout << str[0];
        replacePi(str.substr(1));
    }
}
void towerOfHanoi(int n, char src, char dest, char helper)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, src, helper, dest);
    cout << "Move from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, helper, dest, src);
}

string removeDuplicates(string s)
{
    if (s.length() == 0)
        return " ";

    char first = s[0];
    string ans = removeDuplicates(s.substr(1));

    if (first == ans[0])
    {
        return ans;
    }
    else
    {
        return (first + ans);
    }
}
string moveX(string str)
{
    if (str.length() == 0)
        return "";

    char first = str[0];
    string ans = moveX(str.substr(1));
    if (first == 'x')
    {
        return ans + first;
    }
    else
    {
        return first + ans;
    }
}

void subseq(string str, string ans)
{

    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char first = str[0];
    string ros = str.substr(1);

    subseq(ros, ans);
    subseq(ros, ans + first);
}

void subseqWithAscii(string str, string ans)
{

    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char first = str[0];
    int code = first;
    string ros = str.substr(1);

    subseqWithAscii(ros, ans);
    subseqWithAscii(ros, ans + first);
    subseqWithAscii(ros, ans + to_string(code));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // reverse("binod");
    // replacePi("pppxpixpipp");
    // towerOfHanoi(3, 'A', 'C', 'B');
    // cout << removeDuplicates("aaaabbbbbbxxxxxxzzzz");
    // cout << moveX("axxbdxcefxhix");
    // subseq("ABC", "");
    subseqWithAscii("AB", "");
}