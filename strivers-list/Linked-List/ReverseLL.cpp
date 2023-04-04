// iteratively
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
        {
            return head;
        }
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = curr->next;

        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

// recursively
if (!head || !head->next)
{
    return head;
}
ListNode *finalHead = reverseList(head->next);
ListNode *temp = head->next;
temp->next = head;
head->next = NULL;
return finalHead;