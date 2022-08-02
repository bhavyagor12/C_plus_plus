#include <bits/stdc++.h>
using namespace std;
#define n 100
class Queue
{
private:
    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void enqueue(int x)
    {
        if (back == n - 1)
        {
            cout << "QUEUE IS FULL" << endl;
            return;
        }
        else if (front == -1 && back == -1)
        {
            front++;
            back++;
            arr[back] = x;
        }
        else
        {
            back++;
            arr[back] = x;
        }
    }
    void dequeue()
    {
        if (!isEmpty())
        {
            front++;
        }
        else
        {
            cout << "QUEUE IS EMPTY" << endl;
        }
    }
    void peek()
    {
        if (!isEmpty())
        {
            cout << arr[front] << endl;
        }
        else if (front == back)
        {
            front = -1;
            back = -1;
            return;
        }
        else
        {
            cout << "QUEUE IS EMPTY" << endl;
        }
    }
    bool isEmpty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Queue q;
    cout << q.isEmpty() << endl;
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.enqueue(15);

    cout << q.isEmpty() << endl;
    while (!q.isEmpty())
    {
        q.peek();
        q.dequeue();
    }
    return 0;
}