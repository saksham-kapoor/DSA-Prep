class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &A)
    {
        multimap<int, ListNode *> mp;
        ListNode *newHead = nullptr, *tail;

        for (auto &head : A)
            if (head)
                mp.insert({head->val, head});

        while (mp.size())
        {
            auto it = mp.begin();
            auto &[val, head] = *it;

            if (newHead == nullptr)
            {
                newHead = head;
                tail = head;
            }
            else
            {
                tail->next = head;
                tail = tail->next;
            }

            if (head->next)
                mp.insert({head->next->val, head->next});
            mp.erase(it);
        }

        return newHead;
    }
};