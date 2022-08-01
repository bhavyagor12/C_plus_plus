#include <bits/stdc++.h>
using namespace std;
#define n 100

class Stack
{
private:
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (!isEmpty())
        {
            int deletedValue = arr[top];
            top--;
            cout << "deletedValue = " << deletedValue << endl;
            return;
        }
        cout << "stack is empty" << endl;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    int topOfStack()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
};

int main()
{
    Stack st;
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.topOfStack() << endl;
    st.pop();
    cout << st.topOfStack() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.isEmpty();
    return 0;
}