class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head; // initial checks

        int length = 1;
        ListNode *tail = head;

        // get length and tail pointer
        while (tail->next)
        {
            ++length;
            tail = tail->next;
        }

        // connect tail to head to make it a cycle
        tail->next = head;

        // find actual value of k
        k = k % length;

        // move till newHead
        for (int i = 0; i < length - k; ++i)
            tail = tail->next;

        ListNode *newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};