#include <bits/stdc++.h>
using namespace std;

char nextLetterCeil(vector<char> &alphabets, char val)
{
    int size = alphabets.size();
    int low = 0, high = size - 1;
    char res = '#';

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (alphabets[mid] == val)
        {
            low = mid + 1; // even if the char is present we move
        }
        else if (alphabets[mid] < val)
        {
            low = mid + 1;
        }
        else
        {
            // moving left has potential ans
            res = alphabets[mid];
            high = mid - 1;
        }
    }
    return res;
}

int main()
{
    vector<char> alphabets = {'a', 'c', 'f', 'x'};
    cout << nextLetterCeil(alphabets, 'z') << endl;
    return 0;
}