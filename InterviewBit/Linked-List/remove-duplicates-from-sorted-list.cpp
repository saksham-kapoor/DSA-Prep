ListNode *Solution::deleteDuplicates(ListNode *head)
{
    for (ListNode *p = head; p != nullptr;)
    {
        if (p->next && p->next->val == p->val)
        {
            // delete p->next
            ListNode *del = p->next;
            p->next = p->next->next;
            del->next = nullptr;
            delete (del);
        }
        else
        {
            p = p->next;
        }
    }

    return head;
}
