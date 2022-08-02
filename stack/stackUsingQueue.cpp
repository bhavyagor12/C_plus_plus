#include <bits/stdc++.h>
using namespace std;
class stackUsingQueuePushCostly
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    stackUsingQueuePushCostly()
    {
        N = 0;
    }
    void push(int value)
    {
        q2.push(value);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front()); // to make sure LIFO
            q1.pop();
        } // all elements in q2;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int pop()
    {
        if (q1.empty())
        {
            cout << "QUEUE UNDERFLOW" << endl;
            return -1;
        }
        int x = q1.front();
        q1.pop();
        N--;
        return x;
    }
    int top()
    {
        if (q1.empty())
        {
            cout << "QUEUE UNDERFLOW" << endl;
            return -1;
        }
        return q1.front();
    }
    int size()
    {
        return N;
    }
};

class stackUsingQueuePopCostly
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    stackUsingQueuePopCostly()
    {
        N = 0;
    }
    void push(int value)
    {
        q1.push(value);
        N++;
    }
    int pop() // O(N)
    {
        if (q1.empty())
        {
            cout << "QUEUE UNDERFLOW" << endl;
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        N--;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return x;
    }
    int top()
    {
        if (q1.empty())
        {
            cout << "QUEUE UNDERFLOW" << endl;
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q2.push(x);           // as we are only seeing and not pop we have to push it back
        queue<int> temp = q1; // here we push toq2 to maintain same order
        q1 = q2;
        q2 = temp;

        return x;
    }
    int size()
    {
        return N;
    }
};

int main()
{
    // stackUsingQueuePushCostly st;
    stackUsingQueuePopCostly st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
}