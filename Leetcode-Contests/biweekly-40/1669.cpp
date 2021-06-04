class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *p = list1, *q, *c = list2;

        for (int i = 0; i < a - 1; ++i)
            p = p->next;

        q = p;

        for (int i = 0; i <= b - a + 1; ++i)
            q = q->next;

        while (c->next)
            c = c->next;

        p->next = list2;
        c->next = q;

        return list1;
    }
};