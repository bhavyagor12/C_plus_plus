#include <bits/stdc++.h>
using namespace std;

// using stl
void reverseString(string s)
{
    stack<string> st;
    int sizeOfString = s.length();
    for (int letter = 0; letter < sizeOfString; letter++)
    {
        string word = "";
        while (s[letter] != ' ' && letter < sizeOfString)
        {
            word += s[letter];
            letter++;
        }
        st.push(word);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop(); // acts as a decrementer for the top
    }
    cout << endl;
}
int main()
{
    string s = "Hey, how are you doing?";
    cout << s << endl;
    reverseString(s);
}