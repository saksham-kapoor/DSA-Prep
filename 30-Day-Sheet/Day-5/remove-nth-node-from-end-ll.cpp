/*

A B C D E F G H
n = 2 [FROM END] => A B C D E F _ H => A B C D E F H

Method 1 -> 1. first get length of list say 'len', here len = 8
            2. calculate the node number you want to delete, len-n+1= 8 - 2 + 1 = 7th node
            3. delete 7th node
            4. voila

            [2 PASS SOLUTION]

Method 2 -> A B C D E F G H
            |
           fast
           move fast n times

            A B C D E F G H
                |
            |
           slow
           Now move slow and fast together till fast reaches end

            A B C D E F G H
                      |   |
                      s   f
            
            s->next = s->next->next;
*/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head;

        // move fast n times
        while (n--)
            fast = fast->next;

        // if n = length of list => means to remove head node
        if (fast == nullptr)
            return head->next; // The head need to be removed, do it.

        // move fast till last node
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next; // the one after the slow need to be removed
        return head;
    }
};