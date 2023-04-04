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

void insertAtTail(node *&head, int val)
{

    node *newNode = new node(val); // created a  new node;
    if (head == NULL)
    {
        head = newNode;
        return;
        // here you can simply call insertAtBeginning
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    // as our new node already points to NULL in its next so we simply do nothing
}

void display(node *head)
{

    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtBeginning(node *&head, int val)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    // node *temp = head;
    // head = newNode;
    // newNode->next = temp;

    newNode->next = head;
    head = newNode;
}

void search(node *head, int val)
{
    if (head == NULL)
    {
        cout << "LINKED LIST is empty no value found" << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
            if (head->next == NULL)
            {
                node *todelete = head;
            }
        {
            cout << "found at:" << temp;
            return;
        }
        temp = temp->next;
    }
    cout << "NOT PRESENT" << endl;
}

void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node *&head, int val)
{
    node *temp = head;
    // corner case empty linked list
    if (head == NULL)
    {
        return;
    }
    // only one node present
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    while (temp->next->data != val)
    {
        temp = temp->next;
    } // reach n-1th node
    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void insertAtPos(node *&head, int val, int pos)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        cout << "Linked List is empty! cant insert at pos" << pos << endl;
        return;
    }
    if (pos == 0)
    {
        insertAtBeginning(head, val);
        return;
    }
    int count = 0;
    node *temp = head;
    while (count != pos - 1)
    {
        count++;
        if (temp->next == NULL)
        {
            cout << "POSITION OUTSIDE OF LL" << endl;
            return;
        }
        temp = temp->next;
    }
    node *temp1 = temp->next;
    temp->next = newNode;
    newNode->next = temp1;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 23);
    insertAtTail(head, 12);
    insertAtTail(head, 10);
    insertAtBeginning(head, 5);
    display(head);
    insertAtPos(head, 99, 5);
    // search(head, 13);
    display(head);
    // deletion(head, 23);
    // deleteAtHead(head);
    // display(head);
    return 0;
}

5 0 1 2 3 4 5 0 1 1 2 0 3
