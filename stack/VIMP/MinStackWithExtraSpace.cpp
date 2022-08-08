#include <bits/stdc++.h>
using namespace std;
stack<int> st;
stack<int> supportingStack;

void push(int element)
{
    st.push(element);
    if (supportingStack.size() == 0 || supportingStack.top() >= element)
    {
        supportingStack.push(element);
    }
}

int pop()
{
    int element = st.top();
    st.pop();
    if (element == supportingStack.top())
    {
        supportingStack.pop();
    }
    return element;
}

int minElement()
{
    if (supportingStack.size() == 0)
    {
        return -1;
    }
    return supportingStack.top();
}

int main()
{
    cout << minElement() << endl;
    push(18);
    push(19);
    push(29);
    push(15);
    cout << minElement() << endl;
    cout << "popped this element: " << pop() << endl;
    cout << minElement() << endl;

    return 0;
}