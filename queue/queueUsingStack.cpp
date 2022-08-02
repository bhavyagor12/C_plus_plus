#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> s1, s2;

public:
    void enqueue(int x)
    {
        s1.push(x);
    }
    int dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "QUEUE UNDERFLOW" << endl;
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topVal = s2.top();
        s2.pop();
        return topVal;
    }
    bool isEmpty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        return false;
    }
};

class QueueUsing1Stack
{
    stack<int> s1;

public:
    void enqueue(int x)
    {
        s1.push(x);
    }
    int dequeue()
    {
        if (s1.empty())
        {
            cout << "QUEUE UNDERFLOW" << endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if (s1.empty())
        {
            return x;
        }
        int item = dequeue();
        s1.push(x);
        return item;
    }
    bool isEmpty()
    {
        if (s1.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    QueueUsing1Stack q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}