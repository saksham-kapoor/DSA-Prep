ListNode *Solution::addTwoNumbers(ListNode *A, ListNode *B)
{
    ListNode dummy(0);
    ListNode *last = &dummy;

    int carry = 0;
    while (A && B)
    {
        int sum = A->val + B->val + carry;
        last->next = new ListNode(sum % 10);
        last = last->next;
        carry = sum / 10;

        A = A->next;
        B = B->next;
    }

    while (A)
    {
        int sum = A->val + carry;
        last->next = new ListNode(sum % 10);
        last = last->next;
        carry = sum / 10;
        A = A->next;
    }

    while (B)
    {
        int sum = B->val + carry;
        last->next = new ListNode(sum % 10);
        last = last->next;
        carry = sum / 10;
        B = B->next;
    }

    while (carry)
    {
        int sum = carry;
        last->next = new ListNode(sum % 10);
        last = last->next;
        carry = sum / 10;
    }

    return dummy.next;
}
