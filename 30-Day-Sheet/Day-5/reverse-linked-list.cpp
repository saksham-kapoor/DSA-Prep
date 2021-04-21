// storing head->next in a new pointer in while loop saves us some computation
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *q = nullptr;

        while (head->next)
        {
            ListNode *next = head->next;
            head->next = q;
            q = head;
            head = next;
        }

        head->next = q;
        return head;
    }
};

// using 3 pointers, so that we don't loose track of head->next
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *p = head, *q = nullptr;
        if (!p)
            return head;

        while (p->next)
        {
            head = head->next;
            p->next = q;
            q = p;
            p = head;
        }

        p->next = q;
        head = p;
        return head;
    }
};
