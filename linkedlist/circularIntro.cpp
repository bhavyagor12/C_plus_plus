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

void insertAtHead(node *&head, int val)
{
    node *newNode = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}
void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *newNode = new node(val);
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        cout << "EMPTY LL" << endl;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    node *toDelete = head;
    head = head->next;
    temp->next = head;
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
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void display(node *&head)
{
    if (head == NULL)
    {
        cout << "LL IS EMPTY" << endl;
        return;
    }
    node *temp = head;

    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 23);
    insertAtTail(head, 12);
    insertAtTail(head, 10);
    display(head);
    insertAtHead(head, 90);
    insertAtHead(head, 40);
    display(head);
    deletion(head, 1);
    display(head);

    return 0;
}