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