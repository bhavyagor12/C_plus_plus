#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
void insertAtHead(node *&head, int val)
{
    node *newNode = new node(val);
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}
void insertAtTail(node *&head, int val)
{
    node *newNode = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp; // as doubly linked list
}

void deleteAtHead(node *&head)
{
    node *toDelete = head;
    head = head->next;
    head->prev = NULL;
    delete toDelete;
}
void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    int count = 1;
    node *temp = head;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
    // edge case is last wala node
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    insertAtHead(head, 5);
    display(head);
    deletion(head, 1);
    display(head);
    return 0;
}