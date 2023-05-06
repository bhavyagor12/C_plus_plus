ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummyNode = new ListNode();
    ListNode *temp = dummyNode;
    int sum = 0;
    int carry = 0;

    while (carry != 0 || l1 || l2)
    {
        ListNode *newNode = new ListNode();
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;

        newNode->val = sum % 10;
        carry = sum / 10;
        temp->next = newNode;
        temp = temp->next;
        sum = 0;
    }

    return dummyNode->next;
}