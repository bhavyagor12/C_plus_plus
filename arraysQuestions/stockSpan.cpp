#include <bits/stdc++.h>
using namespace std;
void bruteForce(vector<int> &stocks)
{
    int size = stocks.size();
    int day[size];
    for (int i = 0; i < size; i++)
    {
        int days = 0;
        for (int j = i; j >= 0; j--)
        {
            if (stocks[i] >= stocks[j])
            {
                days++;
            }
            else
            {
                break;
            }
        }
        day[i] = days;
    }
    for (int i = 0; i < size; i++)
    {
        cout << day[i] << endl;
    }
}
int main()
{
    vector<int> stocks = {100, 80, 60, 70, 60, 75, 85};
    bruteForce(stocks);
    return 0;
}