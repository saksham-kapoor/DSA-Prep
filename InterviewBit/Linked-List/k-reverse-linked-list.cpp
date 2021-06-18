// k > 1

ListNode *k_reverse(ListNode *p, int k)
{
    ListNode *m = p->next, *q = m->next;

    for (int i = 1; i <= k - 1; ++i)
    {
        m->next = q->next;
        q->next = p->next;
        p->next = q;
        q = m->next;
    }

    return m;
}

ListNode *Solution::reverseList(ListNode *head, int k)
{

    ListNode dummy(0);
    dummy.next = head;

    ListNode *p = &dummy;

    while (p->next)
        p = k_reverse(p, k);

    return dummy.next;
}
