#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int getBit(int number, int pos)
{

    return (number & (1 << pos)) != 0;
}
int setBit(int number, int pos)
{

    return (number | (1 << pos));
}
int clearBit(int number, int pos)
{
    int onesComplement = ~(1 << pos);
    // called as mask
    return (number & onesComplement);
}

int updateBit(int number, int pos, int value)
{
    int onesComplement = ~(1 << pos);
    number = number & onesComplement;
    return (number | (value << pos));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // cout << getBit(5, 2) << endl;
    // cout << setBit(5, 1) << endl;
    // cout << clearBit(5, 2) << endl;
    cout << updateBit(5, 1, 1) << endl;
}
