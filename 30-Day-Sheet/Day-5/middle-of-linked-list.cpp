/*

Fast pointer moves by 2 steps while slow pointer moves by 1.
when fast reaches end, slow reaches middle.

If even elements => 2 middles => slow reaches the second middle

*/

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};