#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10;
    int *aptr = &a;
    // cout << *aptr << endl;
    // *aptr = 20;
    // cout << *aptr << endl;

    int arr[] = {10, 20, 30};
    cout << *arr << endl;
    int *ptr = arr; // as arr already stores address
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << *ptr << endl;
    //     ptr++;
    // }
    for (int i = 0; i < 3; i++)
    {
        cout << *(arr + i) << endl;
        // arr++; // not possible to do
    }
}