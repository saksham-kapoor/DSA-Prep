/*

Fairly easy to understand
O(M+N) solution

*/

ListNode *Solution::addTwoNumbers(ListNode *A, ListNode *B)
{
    ListNode final_sum(0);
    ListNode *C = &final_sum;
    int carry = 0;

    while (A || B || carry)
    {
        int sum = carry;
        sum += ((A) ? A->val : 0);
        sum += ((B) ? B->val : 0);

        carry = sum / 10;
        sum = sum % 10;

        C->next = new ListNode(sum);
        C = C->next;

        if (A)
            A = A->next;
        if (B)
            B = B->next;
    }

    return final_sum.next;
}