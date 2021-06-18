ListNode *get_mid(ListNode *head)
{
    ListNode *fast = head, *slow = head;
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

bool compare(ListNode *p, ListNode *q)
{
    while (p && q)
    {
        if (p->val != q->val)
            return false;
        p = p->next;
        q = q->next;
    }
    return true;
}

int Solution::lPalin(ListNode *head)
{
    ListNode *mid = get_mid(head);
    ListNode *rev = reverse(mid->next);

    return compare(head, rev);
}
