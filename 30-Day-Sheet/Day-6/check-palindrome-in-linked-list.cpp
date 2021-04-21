/*

Method 1 -> Stack Method
            O(N) time
            O(N) space
            
Method 2 -> Reversing first half of linked list
            and comparing the first and second halves
            
            pretty straight forward code
            do a dry run for length odd/even

*/

class Solution
{
    bool compareLists(ListNode *A, ListNode *B)
    {
        while (A && B)
        {
            if (A->val != B->val)
                return false;
            A = A->next;
            B = B->next;
        }

        if (A || B)
            return false;
        return true;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *prev = nullptr;

        while (fast && fast->next)
        {
            fast = fast->next->next;

            ListNode *temp = slow;
            slow = slow->next;
            temp->next = prev;
            prev = temp;
        }

        if (fast)
            slow = slow->next;

        return compareLists(prev, slow);
    }
};

// Stack Method
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> vals;
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            vals.push(slow->val);
            slow = slow->next;
        }

        if (fast)
            slow = slow->next;

        while (slow)
        {
            if (vals.top() != slow->val)
                return false;
            vals.pop();
            slow = slow->next;
        }

        return true;
    }
};