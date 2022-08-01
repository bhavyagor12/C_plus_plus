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

void intersect(node *&headLL1, node *&headLL2, int pos)
{
    node *temp1 = headLL1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    node *temp2 = headLL2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int lengthFinder(node *head)
{
    int length = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}
// time complexity -- O(length of the longer LL);
int intersection(node *&headLL1, node *&headLL2)
{
    int lengthOfLL1 = lengthFinder(headLL1);
    int lengthOfLL2 = lengthFinder(headLL2);

    int difference = 0;
    node *ptr1, *ptr2; // ptr1 is for longer LL and ptr2 is for shorter LL

    if (lengthOfLL1 >= lengthOfLL2)
    {
        difference = lengthOfLL1 - lengthOfLL2;
        ptr1 = headLL1;
        ptr2 = headLL2;
    }
    else
    {
        difference = lengthOfLL2 - lengthOfLL1;
        ptr1 = headLL2;
        ptr2 = headLL1;
    }

    while (difference)
    {
        ptr1 = ptr1->next; // as both have to start from the same point
        if (ptr1 == NULL)
        {
            return -1; // length over before meeting starting point
        }
        difference--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data; // know the data where it is same;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main()
{
    node *headLL1 = NULL;
    node *headLL2 = NULL;
    insertAtTail(headLL1, 1);
    insertAtTail(headLL1, 2);
    insertAtTail(headLL1, 3);
    insertAtTail(headLL1, 4);
    insertAtTail(headLL1, 5);
    insertAtTail(headLL1, 6);
    insertAtTail(headLL2, 9);
    insertAtTail(headLL2, 10);
    intersect(headLL1, headLL2, 3);
    display(headLL1);
    display(headLL2);
    cout << intersection(headLL1, headLL2) << endl;

    return 0;
}