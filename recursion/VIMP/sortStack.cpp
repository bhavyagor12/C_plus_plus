#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &st, int topEle)
{
    // as stack top should have top ele to be greater
    //  if it is smaller we have to remove
    // till we get bigger element
    if (st.size() == 0 || st.top() >= topEle)
    {
        st.push(topEle);
        return;
    }
    int val = st.top();
    st.pop();
    insert(st, topEle);
    st.push(val);
}

void stackSort(stack<int> &st)
{
    // base condition when stack has one ele
    if (st.size() == 1)
    {
        return; // as one element is always sorted
    }
    int topEle = st.top();
    st.pop();
    stackSort(st);
    insert(st, topEle);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(7);
    st.push(3);
    st.push(2);
    cout << st.top() << endl;
    stackSort(st);
    cout << "after stack sorting" << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}