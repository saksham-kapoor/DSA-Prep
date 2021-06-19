// O(NlogK) Time
// K = number of lists
// Good Complexity
class Solution
{
    typedef pair<int, ListNode *> pil;

public:
    ListNode *mergeKLists(vector<ListNode *> &A)
    {
        priority_queue<pil, vector<pil>, greater<pil>> pq;
        ListNode *p = nullptr, *t;

        for (auto &head : A)
            if (head)
                pq.push({head->val, head});

        while (!pq.empty())
        {
            auto &[val, head] = pq.top();

            if (p == nullptr)
            {
                p = head;
                t = head;
            }
            else
            {
                t->next = head;
                t = t->next;
            }

            if (head->next)
                pq.push({head->next->val, head->next});
            pq.pop();
        }

        return p;
    }
};

// O(NlogN) Time
// O(N) Space
// Bad complexity
void addFront(int x, ListNode **head)
{
    if (*head == nullptr)
    {
        *head = new ListNode(x);
        return;
    }
    ListNode *node = new ListNode(x);
    node->next = *head;
    *head = node;
}

ListNode *Solution::mergeKLists(vector<ListNode *> &A)
{
    priority_queue<int> pq;

    for (int i = 0; i < A.size(); ++i)
    {
        ListNode *head = A[i];
        while (head)
        {
            pq.push(head->val);
            head = head->next;
        }
    }

    ListNode *head = nullptr;
    while (pq.size())
    {
        int x = pq.top();
        pq.pop();

        addFront(x, &head);
    }
    return head;
}
