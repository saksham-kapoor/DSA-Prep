// O(1) Solution -> better solution!
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete (temp);
    }
};

// O(N) solution
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        while (node->next->next)
        {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        node->next = nullptr;
    }
};
