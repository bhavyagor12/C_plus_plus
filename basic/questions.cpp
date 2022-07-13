// reverse a number

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // !!!! reverse a number
    // int n;
    // cin >> n;
    // int rem, result = 0;

    // while (n > 0)
    // {
    //     rem = n % 10;
    //     result = result * 10 + rem;
    //     n = n / 10;
    // }
    // cout << result << endl;

    // !!!!  prime number
    // int n;
    // cin >> n;
    // bool flag = 0;
    // for (int i = 2; i < sqrt(n); i++)
    // {
    //     if (n % i == 0)
    //     {
    //         cout << "non prime" << endl;
    //         flag = 1;
    //         break;
    //     }
    // }
    // if (flag == 0) // int n;
    // cin >> n;
    // int rem, result = 0;
    // while (n > 0)
    // {
    //     rem = n % 10;
    //     result = result * 10 + rem;
    //     n = n / 10;
    // }
    // cout << result << endl;
    // {
    //     cout << "prime number" << endl;
    // }

    // !! Armstrong numberr
    // 153 is armstrong as taken cube of indidual digits the
    // sum of them will give same answer 1 cube is 1,  5 cube is 125, 3 cube is 27
    // add them the ans is 153

    int n;
    cin >> n;
    int original = n;
    int sum = 0, rem;
    while (n > 0)
    {
        rem = n % 10;
        sum += pow(rem, 3);
        n = n / 10;
    }
    if (sum == original)
    {
        cout << "Armstrong number" << endl;
    }
    else
    {
        cout << "Non armstrong number" << endl;
    }
}