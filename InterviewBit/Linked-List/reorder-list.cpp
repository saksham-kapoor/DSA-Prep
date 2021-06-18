ListNode *get_mid(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr, *curr = head, *next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode *Solution::reorderList(ListNode *head)
{
    ListNode *mid = get_mid(head);
    if (mid == head)
        return head;
    ListNode *q = reverse(mid->next);

    ListNode *p = head;

    while (p && q)
    {
        ListNode *q_next = q->next;
        ListNode *p_next = p->next;
        q->next = p->next;
        p->next = q;
        q = q_next;
        p = p_next;
    }

    if (p)
        p->next = nullptr;
    if (q)
        q->next = nullptr;

    return head;
}
