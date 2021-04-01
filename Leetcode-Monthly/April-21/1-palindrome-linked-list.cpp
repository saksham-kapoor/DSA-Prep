/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *newHead = nullptr;
        while (head)
        {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }

    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *middle = middleNode(head);
        middle->next = reverseLinkedList(middle->next);
        middle = middle->next;

        while (middle)
        {
            if (head->val != middle->val)
                return false;
            head = head->next;
            middle = middle->next;
        }
        return true;
    }
};