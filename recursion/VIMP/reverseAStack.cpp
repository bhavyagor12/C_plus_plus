#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &st, int topEle)
{
    if (st.size() == 0) // logic only push to the bottom
    {
        st.push(topEle);
        return;
    }
    int val = st.top(); // removes the top ofthe stack
    st.pop();
    insert(st, topEle); // insertAtBottom
    st.push(val);       // pushes stack top value when
}
void stackReverse(stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }
    int topEle = st.top();
    st.pop();
    stackReverse(st);
    insert(st, topEle);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(7);
    st.push(3);
    st.push(2);
    stackReverse(st);
    cout << "after stack reverse" << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}