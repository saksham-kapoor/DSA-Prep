/*

Method 1 -> Brute Force
            O(m*n) time
            O(1) space
            Traverse linked list A for each node in B, check if they intersect
            
Method 2 -> Better Method
            O(m+n) time
            O(1) space
            
            traverse list A and modify each value by multiplying by -1
            traverse list B, check if any value negative
            if yes
            return that node
            else
            return null as lists do not intersect
                

Method 3 -> Take two pointers and place on headA, headB
            
            Any time they collide or reach end together without colliding 
            then return any one of the pointers.

            If one of them reaches the end earlier then reuse it 
            by moving it to the beginning of other list.
            Once both of them go through reassigning, 
            they will be equidistant from the collision point.
                        
*/

// Method 1
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA, *curB = headB;

        // if any list is empty
        if (!curA || !curB)
            return nullptr;

        while (curA && curB)
        {
            if (curA == curB)
                return curA;

            curA = curA->next;
            curB = curB->next;

            if (!curA && !curB)
                return nullptr;

            if (!curA)
                curA = headB;
            if (!curB)
                curB = headA;
        }

        return curA;
    }
};

// Method 2
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p = headA;
        ListNode *intersection = nullptr;

        // mark all values as negative in listA
        while (p)
        {
            p->val = -p->val;
            p = p->next;
        }

        p = headB;
        // check for first negative value in listB
        while (p)
        {
            if (p->val < 0)
            {
                intersection = p;
                break;
            }
            p = p->next;
        }

        ListNode *q = headA;
        // mark all values as positive in listA
        while (q)
        {
            q->val = -1 * q->val;
            q = q->next;
        }

        return intersection;
    }
};