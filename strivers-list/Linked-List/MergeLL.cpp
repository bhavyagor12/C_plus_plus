/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode();
        ListNode *ptr = dummy;
        ListNode *newHead = ptr;

        ListNode *ll1 = list1;
        ListNode *ll2 = list2;

        while (ll1 && ll2)
        {
            if (ll1->val <= ll2->val)
            {
                newHead->next = ll1;
                newHead = newHead->next;
                ll1 = ll1->next;
            }
            else
            {
                newHead->next = ll2;
                newHead = newHead->next;
                ll2 = ll2->next;
            }
        }
        while (ll1)
        {
            newHead->next = ll1;
            newHead = newHead->next;
            ll1 = ll1->next;
        }
        while (ll2)
        {
            newHead->next = ll2;
            newHead = newHead->next;
            ll2 = ll2->next;
        }

        return ptr->next;
    }
};

//

if (list1 == NULL)
    return list2;
if (list2 == NULL)
    return list1;

if (list1->val > list2->val)
{
    std::swap(list1, list2);
}
ListNode *res = list1;

while (list1 && list2)
{
    ListNode *temp = NULL;
    while (list1 && list1->val <= list2->val)
    {
        temp = list1;
        list1 = list1->next;
    }
    temp->next = list2;
    std::swap(list1, list2);
}

return res;