// O(1) space solution
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

ListNode *Solution::solve(ListNode *head)
{
    th = tt = nullptr;
    ListNode *p = head;

    while (p && p->next)
    {
        ListNode *even = p->next;
        p->next = p->next->next;
        p = p->next;

        addFront(even);
    }

    p = head;
    ListNode *q = th;

    while (p && q)
    {
        ListNode *next = q->next;
        q->next = p->next;
        p->next = q;
        p = q->next;
        q = next;
    }

    return head;
}

// O(n) space solution
ListNode *Solution::solve(ListNode *head)
{
    stack<int> st;
    ListNode *p = head;
    for (int i = 0; p != nullptr; ++i, p = p->next)
        if (i & 1)
            st.push(p->val);

    p = head;

    for (int i = 0; p != nullptr; ++i, p = p->next)
        if (i & 1)
            p->val = st.top(), st.pop();

    return head;
}
