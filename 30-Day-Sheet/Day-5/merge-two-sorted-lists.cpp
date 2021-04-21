// Iterative Solution
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode merged(0);
        ListNode *p = &merged;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                // attach l1
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                // attach l2
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if (l1)
            p->next = l1;
        if (l2)
            p->next = l2;

        return merged.next;
    }
};

// Recursive Solution, IBH method
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};