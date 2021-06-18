ListNode *Solution::detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // no cycle
    if (slow != fast)
        return nullptr;

    // if cycle
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
