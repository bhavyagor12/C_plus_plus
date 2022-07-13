#include <bits/stdc++.h>
using namespace std;

// prime numbers print from a-b range given by user
// bool isPrime(int num)
// {
//     for (int i = 2; i < sqrt(num); i++)
//     {
//         if (num % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     int a, b;
//     cin >> a >> b;

//     for (int i = a; i <= b; i++)
//     {
//         if (isPrime(i))
//         {
//             cout << i << endl;
//         }
//     }
// }

// fibonnaci sequence
//  next term is sum of the previous terms

// void fib(int n)
// {
//     int firstTerm = 0;
//     int secondTerm = 1;
//     cout << firstTerm << " " << secondTerm << " ";
//     int nextTerm = firstTerm + secondTerm;
//     while (nextTerm <= n)
//     {
//         cout << nextTerm << " ";
//         firstTerm = secondTerm;
//         secondTerm = nextTerm;
//         nextTerm = firstTerm + secondTerm;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     fib(n);
// }

// Factorial of a numberr
// 4! is 4*3*2*1 = 24
// void factorial(int n)
// {
//     int fact = 1;
//     for (int i = n; i > 1; i--)
//     {
//         fact = fact * i;
//     }
//     cout << fact << endl;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     factorial(n);
// }

// Binary coefficient of a number
// nCr = n! / (n-r)! * r!
// int factorial(int n)
// {
//     int fact = 1;
//     for (int i = n; i > 1; i--)
//     {
//         fact = fact * i;
//     }
//     return fact;
// }
// int main()
// {
//     int n, r;
//     cin >> n >> r;
//     int a = factorial(n);
//     int b = factorial(r);
//     int d = factorial(n - r);

//     int nCr = a / (b * d);
//     cout << nCr << endl;
// }

// pascal triangle (BINARY COEFFEICIENT TABLE)

// int factorial(int n)
// {
//     int fact = 1;
//     for (int i = n; i > 1; i--)
//     {
//         fact = fact * i;
//     }
//     return fact;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             cout << factorial(i) / (factorial(j) * factorial(i - j)) << " ";
//         }
//         cout << endl;
//     }
// }

// Sum of first n natural numbers
// sum = n(n+1) / 2 .. so if n is 4, then sum till 4 is 1+2+3+4 = 10 or 4*5/2

// void sumTillN(int n)
// {
//     int sum = n * (n + 1) / 2;
//     cout << sum << endl;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     sumTillN(n);
// }

/// Pythagorian triplet

// bool pythagorianTriplet(int x, int y, int z)
// {
//     int a = max(x, max(y, z)); // max takes in only 2 arguments
//     int b, c;
//     if (a == x)
//     {
//         b = y;
//         c = z;
//     }
//     else if (a == y)
//     {
//         b = x;
//         c = z;
//     }
//     else
//     {
//         b = x;
//         c = y;
//     }

//     if (a * a == b * b + c * c)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// int main()
// {
//     int x, y, z;
//     cin >> x >> y >> z;
//     if (pythagorianTriplet(x, y, z))
//     {
//         cout << "Pythagorian Triplet" << endl;
//     }
//     else
//     {
//         cout << "Not Pythagorian Triplet" << endl;
//     }
// }

// binary to decimal conversion
// int binaryToDecimal(int n)
// {
//     int ans = 0;
//     int base = 1;
//     while (n > 0)
//     {
//         int rem = n % 10;
//         ans += base * rem;
//         base *= 2;
//         n = n / 10;
//     }
//     return ans;
// }
// int octalToDecimal(int n)
// {
//     int ans = 0;
//     int base = 1;
//     while (n > 0)
//     {
//         int rem = n % 10;
//         ans += base * rem;
//         base *= 8;
//         n = n / 10;
//     }
//     return ans;
// }
// int hexaToDecimal(string n)
// {
//     int ans = 0;
//     int base = 1;
//     int size = n.size();
//     for (int i = size - 1; i >= 0; i--)
//     {
//         if (n[i] >= '0' && n[i] <= '9')
//         {
//             ans += base * (n[i] - '0');
//         }
//         else if (n[i] >= 'A' && n[i] <= 'F')
//         {
//             ans += base * (n[i] - 'A' + 10);
//         }
//         base *= 16;
//     }
//     return ans;
// }
// int decimalToBinary(int n)
// {
//     int ans = 0;
//     int base = 1;
//     while (base <= n)
//     {
//         base *= 2;
//     }
//     base /= 2;
//     while (base > 0)
//     {
//         int lastDigit = n / base;
//         n -= lastDigit * base;
//         base /= 2;
//         ans = ans * 10 + lastDigit;
//     }
//     return ans;
// }
// int decimalToOctal(int n)
// {
//     int ans = 0;
//     int base = 1;
//     while (base <= n)
//     {
//         base *= 8;
//     }
//     base /= 8;
//     while (base > 0)
//     {
//         int lastDigit = n / base;
//         n -= lastDigit * base;
//         base /= 8;
//         ans = ans * 10 + lastDigit;
//     }
//     return ans;
// }
// string decimalToHexadecimal(int n)
// {
//     string ans = "";
//     int base = 1;
//     while (base <= n)
//     {
//         base *= 16;
//     }
//     base /= 16;
//     while (base > 0)
//     {
//         int lastDigit = n / base;
//         n -= lastDigit * base;
//         base /= 16;
//         if (lastDigit <= 9)
//         {
//             ans = ans + to_string(lastDigit);
//         }
//         else
//         {
//             char c = 'A' + lastDigit - 10;
//             ans.push_back(c);
//         }
//     }
//     return ans;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     // cout << binaryToDecimal(n) << endl;
//     // cout << octalToDecimal(n) << endl;
//     // string n;
//     // cin >> n;
//     // cout << hexaToDecimal(n) << endl;
//     // cout << decimalToBinary(n) << endl;
//     // cout << decimalToOctal(n) << endl;
//     cout << decimalToHexadecimal(n) << endl;
// }

/// Adding of 2 binary numbers
int reverse(int n)
{
    int ans = 0, rem;
    while (n > 0)
    {
        rem = n % 10;
        ans = ans * 10 + rem;
        n = n / 10;
    }
    return ans;
}
int addBinaryNumber(int n1, int n2)
{
    int ans = 0;
    int previousCarry = 0;
    while (n1 > 0 && n2 > 0)
    {
        if (n1 % 2 == 0 && n2 % 2 == 0)
        {
            ans = ans * 10 + previousCarry;
            previousCarry = 0;
        }
        else if ((n1 % 2 == 1 && n2 % 2 == 0) || (n1 % 2 == 0 && n2 % 2 == 1))
        {
            if (previousCarry == 1)
            {
                ans = ans * 10 + 0;
                previousCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                previousCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + previousCarry;
            previousCarry = 1;
        }
        n1 /= 10;
        n2 /= 10;
    }
    while (n1 > 0)
    {
        if (previousCarry == 1)
        {
            if (n1 % 2 == 1)
            {
                ans = ans * 10 + 0;
                previousCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                previousCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (n1 % 2);
        }
    }
    n1 /= 10;
    while (n2 > 0)
    {
        if (previousCarry == 1)
        {
            if (n2 % 2 == 1)
            {
                ans = ans * 10 + 0;
                previousCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                previousCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (n2 % 2);
        }
    }
    n2 /= 10;

    if (previousCarry == 1)
    {
        ans = ans * 10 + 1;
    }
    ans = reverse(ans);
    return ans;
}
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    cout << addBinaryNumber(n1, n2) << endl;
}