/*

Method 1 -> modify traversed values so we can differentiate between visited/unvisited nodes
            NOT RECOMMENDED

Method 2 -> TORTOISE AND HARE METHOD
            OR
            SLOW AND FAST METHOD
            OR
            WALKER AND RUNNER METHOD

*/

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};