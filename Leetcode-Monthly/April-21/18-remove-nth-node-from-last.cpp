// 1 pass solution
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *h1 = head, *h2 = head;
        while (n--)
            h2 = h2->next;
        if (h2 == nullptr)
            return head->next; // The head need to be removed, do it.

        h2 = h2->next;

        while (h2 != nullptr)
        {
            h1 = h1->next;
            h2 = h2->next;
        }

        h1->next = h1->next->next; // the one after the h1 need to be removed
        return head;
    }
};

// 2 pass solution
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int sz = 0;
        ListNode *p = head;
        while (p)
        {
            ++sz;
            p = p->next;
        }

        n = sz - n;
        ListNode *q = nullptr;
        p = head;

        for (int i = 0; i < n; ++i)
        {
            q = p;
            p = p->next;
        }

        // delete node
        if (p == head)
            head = p->next;
        else
            q->next = p->next;

        p->next = nullptr;
        delete (p);

        return head;
    }
};