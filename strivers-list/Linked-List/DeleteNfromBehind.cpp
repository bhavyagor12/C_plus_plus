ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummyNode = head;

    int N = 0;
    while (dummyNode)
    {
        dummyNode = dummyNode->next;
        N++;
    }
    int value = N - n;
    if (n >= N)
    {
        return head->next;
    } // maybenot needed edge case

    ListNode *prevNode = head;

    if (value == 0) // if first node
    {
        head = head->next;
        delete (prevNode);
        return head;
    }
    while (value != 1) // not last node;
    {
        prevNode = prevNode->next;
        value--;
    }
    ListNode *node = prevNode->next;
    prevNode->next = prevNode->next->next;
    delete (node);
    return head;
}