ListNode *th = nullptr, *tt = nullptr;

void addBack(ListNode *node)
{
    if (th == nullptr)
    {
        th = tt = node;
        node->next = nullptr;
        return;
    }
    node->next = nullptr;
    tt->next = node;
    tt = tt->next;
}

ListNode *Solution::mergeTwoLists(ListNode *A, ListNode *B)
{
    th = tt = nullptr;
    ListNode *next = nullptr;

    while (A && B)
    {
        if (A->val < B->val)
        {
            next = A->next;
            addBack(A);
            A = next;
        }
        else
        {
            next = B->next;
            addBack(B);
            B = next;
        }
    }

    while (A)
    {
        next = A->next;
        addBack(A);
        A = next;
    }

    while (B)
    {
        next = B->next;
        addBack(B);
        B = next;
    }

    return th;
}
