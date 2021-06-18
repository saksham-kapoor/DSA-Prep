// 1 pass approach
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *n1 = nullptr, *n2 = nullptr;

        for (ListNode *p = head; p != nullptr; p = p->next)
        {
            n2 = n2 == nullptr ? n2 : n2->next;
            if (--k == 0)
            {
                n1 = p;
                n2 = head;
            }
        }

        swap(n1->val, n2->val);

        return head;
    }
};

// 2 pass approach
// calculating the length first
// then placing pointers
// then swapping
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        int l = 0;
        ListNode *p = head, *q = head;

        while (p)
            ++l, p = p->next;

        p = head;

        for (int i = 0; i < k - 1; ++i)
            p = p->next;

        for (int i = 0; i < l - k; ++i)
            q = q->next;

        swap(p->val, q->val);

        return head;
    }
};