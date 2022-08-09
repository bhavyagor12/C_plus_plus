#include <bits/stdc++.h>
using namespace std;
int minEle = INT_MAX;
stack<int> st;

void push(int num)
{
    if (st.empty())
    {
        minEle = num;
        st.push(num);
    }
    else if (minEle > num)
    {
        int flag = (2 * num) - minEle;
        minEle = num;
        st.push(flag);
    }
    else if (minEle <= num)
    {
        st.push(num);
    }
}

int pop()
{
    if (st.empty())
    {
        return -1;
    }
    else if (st.top() < minEle)
    {
        int poppedEle = minEle;
        int flag = (2 * poppedEle) - st.top();
        minEle = flag;
        st.pop();
        return poppedEle;
    }
    else
    {
        return st.top();
    }
}

int top()
{
    if (st.empty())
    {
        return -1;
    }
    else if (st.top() < minEle)
    {
        return minEle;
    }
    else
    {
        return st.top();
    }
}

int getMinElement()
{
    if (st.empty())
    {
        return -1;
    }
    return minEle;
}
int main()
{
    cout << getMinElement() << endl;
    push(5);
    cout << getMinElement() << endl;
    push(3);
    cout << top() << endl;
    cout << getMinElement() << endl;
    cout << pop() << endl;
    cout << getMinElement();
    return 0;
}