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

void oddEven(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenStart = even;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    if (odd->next != NULL)
    {
        even->next = NULL;
    }
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    oddEven(head);
    display(head);
    return 0;
}