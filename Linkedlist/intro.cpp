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
        {
            cout << "found at:" << temp;
            return;
        }
        temp = temp->next;
    }
    cout << "NOT PRESENT" << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 23);
    insertAtTail(head, 12);
    insertAtTail(head, 10);
    insertAtBeginning(head, 5);
    search(head, 13);
    // display(head);
    return 0;
}