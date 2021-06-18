// 1 pass solution
int Solution::solve(ListNode *head, int k)
{
    ListNode *p = head, *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (--k < 0)
            p = p->next;
    }

    if (k > 0)
        return -1;

    return p->val;
}

// 2 pass solution
int Solution::solve(ListNode *head, int k)
{
    int mid = 0;
    ListNode *slow = head, *fast = head;

    while (fast && fast->next)
    {
        ++mid;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (k > mid)
        return -1;

    ListNode *res = head;

    for (int i = 1; i <= mid - k; ++i)
        res = res->next;

    return res->val;
}
