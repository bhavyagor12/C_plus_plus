// rectangle pattern
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /// !!!! RECTANGLE PATTERN !!!!
    // int r, c;
    // cin >> r >> c;
    // for (int i = 1; i <= r; i++)
    // {
    //     for (int j = 1; j <= c; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // return 0;

    /// !!!! HOLLOW RECTANGLE PATTERN !!!!
    // int r, c;
    // cin >> r >> c;
    // for (int i = 1; i <= r; i++)
    // {
    //     for (int j = 1; j <= c; j++)
    //     {
    //         if (i == 1 || i == r || j == 1 || j == c)
    //         {
    //             cout << "*";
    //         }
    //         else
    //         {
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    /// !!!!INVERTED HALF PYRAMID
    // int n;
    // cin >> n;
    // for (int i = n; i >= 1; i--)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // return 0;

    /// !!!!HALF PYRAMID AFTER 180 DEGREE ROTATION
    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (j <= n - i)
    //         {
    //             cout << " ";
    //         }
    //         else
    //         {
    //             cout << "*";
    //         }
    //     }
    //     cout << endl;
    // }
    // return 0;

    /// !!!!numbers
    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << i;
    //     }
    //     cout << endl;
    // }
    // return 0;

    /// !!!!floyds triangle
    // int n;
    // cin >> n;
    // int num = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << num << " ";
    //         num++;
    //     }
    //     cout << endl;
    // }
    // return 0;

    /// !!!!BUTTERFLY PATTERN
    // int n;
    // cin >> n;
    // int n2 = n * 2;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << "*";
    //     }
    //     int space = n2 - 2 * i;
    //     for (int j = 1; j <= space; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << "*";
    //     }

    //     cout << endl;
    // }
    // for (int i = n; i >= 1; i--)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << "*";
    //     }
    //     int space = n2 - 2 * i;
    //     for (int j = 1; j <= space; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << "*";
    //     }

    //     cout << endl;
    // }

    // inverted number pattern
    // int n;
    // cin >> n;
    // for (int i = n; i >= 1; i--)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    // return 0;

    // 0 - 1 pattern(even numbers had 1s in their place)
    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         if ((i + j) % 2 == 0)
    //         {
    //             cout << "1";
    //         }
    //         else
    //         {
    //             cout << "0";
    //         }
    //     }
    //     cout << endl;
    // }
    // return 0;

    /// !!!! Rhombus pattern
    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     int spaces = n - i;
    //     for (int j = 1; j <= spaces; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    /// !!!! unique number pattern
    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     int spaces = n - i;
    //     for (int j = 1; j <= spaces; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    /// !!!! palidromic pattern (VVV imp)
    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     int j;
    //     for (j = 1; j <= n - i; j++)
    //     {
    //         cout << " ";
    //     }
    //     int k = i;
    //     for (; j <= n; j++)
    //     {
    //         cout << k--;
    //     }
    //     k = 2;
    //     for (; j <= n + i - 1; j++)
    //     {
    //         cout << k++;
    //     }
    //     cout << endl;
    // }

    /// !!!!STAR pattern
    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     int j;
    //     for (j = 1; j <= n - i; j++)
    //     {
    //         cout << " ";
    //     }

    //     for (j = 1; j <= 2 * i - 1; j++)
    //     {
    //         cout << "*";
    //     }

    //     cout << endl;
    // }
    // for (int i = n; i >= 1; i--)
    // {
    //     int j;
    //     for (j = 1; j <= n - i; j++)
    //     {
    //         cout << " ";
    //     }

    //     for (j = 1; j <= 2 * i - 1; j++)
    //     {
    //         cout << "*";
    //     }

    //     cout << endl;
    // }

    /// !!!!zig zag pattern

    // no of stars is 9 equal to n, rows is 3(n/3), cols

    // int n;
    // cin >> n;

    // for (int i = 1; i <= 3; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if ((i + j) % 4 == 0 || i == 2 && j % 4 == 0)
    //         {
    //             cout << "*";
    //         }
    //         else
    //         {
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }
}
