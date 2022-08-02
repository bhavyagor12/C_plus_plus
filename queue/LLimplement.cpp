#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    node *front;
    node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    void enqueue(int x)
    {
        node *newNode = new node(x);
        if (front == NULL)
        {
            back = newNode;
            front = newNode;
            return;
        }
        back->next = newNode;
        back = newNode;
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "EMPTY QUEUE" << endl;
            return;
        }
        if (front == back)
        {
            node *toDelete = front;
            cout << toDelete->data << endl;
            front = NULL;
            back = NULL;
        }
        node *toDelete = front;
        front = front->next;
        cout << toDelete->data << endl;
        delete toDelete;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "EMPTY QUEUE" << endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Queue q;
    cout << q.isEmpty() << endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.isEmpty() << endl;
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;

    return 0;
}