#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

// void primeSieve(int n)
// {
//     int prime[100] = {0};
//     // empty array initialized with 0 values

//     for (int i = 2; i < sqrt(n); i++)
//     {
//         if (prime[i] == 0)
//         {
//             for (int j = i * i; j <= n; j += i)
//             {
//                 prime[j] = 1;
//             }
//         }
//     }

//     for (int i = 2; i < n; i++)
//     {
//         if (prime[i] == 0)
//         {
//             cout << i << " ";
//         }
//     }
// }

// prime numbers in a given range
void primeSieve1(int a, int b)
{
    int prime1[1000] = {0};
    // empty array initialized with 0 values

    for (int i = a; i < sqrt(b); i++)
    {
        if (prime1[i] == 0)
        {
            for (int j = i * i; j <= b; j += i)
            {
                prime1[j] = 1;
            }
        }
    }

    for (int i = a; i < b; i++)
    {
        if (prime1[i] == 0)
        {
            cout << i << " ";
        }
    }
}

// void primeFactor(int n)
// {
//     int spf[100] = {0};
//     for (int i = 2; i <= n; i++)
//     {
//         spf[i] = i;
//     }
//     for (int i = 2; i <= n; i++)
//     {
//         if (spf[i] == i)
//         {
//             for (int j = i * i; j <= n; j += i)
//             {
//                 if (spf[j] == j)
//                 {
//                     spf[j] = i;
//                 }
//             }
//         }
//     }

//     while (n != 1)
//     {
//         cout << spf[n] << " ";
//         n = n / spf[n];
//     }
// }
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
    // primeSieve(n);
    // int n;
    // cin >> n;
    // primeFactor(n);
    int a, b;
    cin >> a >> b;
    primeSieve1(a, b);
}