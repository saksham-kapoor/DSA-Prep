/*

Method -> TORTOISE AND HARE METHOD

This method wwas also used to find duplicate in array

*/

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        bool cycle = false;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                cycle = true;
                break;
            }
        }

        if (!cycle)
            return nullptr;

        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};