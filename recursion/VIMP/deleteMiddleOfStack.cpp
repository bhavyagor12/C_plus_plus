#include <bits/stdc++.h>
using namespace std;
void deleteMiddle(stack<int> &st, int middle)
{
    if (middle == 1)
    {
        st.pop();
        return;
    }
    int val = st.top();
    st.pop();
    deleteMiddle(st, middle - 1);
    st.push(val);
}
int main()
{
    stack<int> st;
    st.push(6);
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    cout << "before stack deleting" << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    st.push(6);
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    cout << "after stack deleting" << endl;
    int size = st.size();
    cout << size << endl;
    int middle = size / 2 + 1; // incase of even take upper middle
    deleteMiddle(st, middle);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}