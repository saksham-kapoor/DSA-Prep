// Swap Actual Nodes
ListNode *th, *tt;

void addFront(ListNode *node)
{
    if (th == nullptr)
    {
        th = tt = node;
        node->next = nullptr;
        return;
    }
    node->next = th;
    th = node;
}

void addBack(ListNode *node)
{
    if (th == nullptr)
    {
        th = tt = node;
        node->next = nullptr;
        return;
    }
    tt->next = node;
    node->next = nullptr;
    tt = tt->next;
}

ListNode *Solution::solve(ListNode *head)
{
    th = tt = nullptr;

    while (head)
    {
        ListNode *next = head->next;
        if (head->val == 0)
            addFront(head);
        else
            addBack(head);
        head = next;
    }

    return th;
}

// Swap values only
ListNode *Solution::solve(ListNode *head)
{
    int zeros = 0;

    for (ListNode *p = head; p; p = p->next)
        zeros += 1 - p->val;

    for (ListNode *p = head; p; p = p->next)
        p->val = zeros-- > 0 ? 0 : 1;

    return head;
}