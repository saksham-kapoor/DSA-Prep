// 1 pass solution

// General Idea -> Put all smaller elements into 'left' list
// and put larger/equal elements into 'right' list
// combine the two in the end
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode left(0), right(0);
        ListNode *p, *q;
        p = &left;
        q = &right;

        while (head)
        {
            if (head->val < x)
                p = p->next = head; // assign it to list1 with head as left
            else
                q = q->next = head; // assign it to list2 with head as right

            // q -> next = head;
            // q = q->next;

            head = head->next;
        }

        q->next = nullptr; // important otherwise, endless loop
        p->next = right.next;
        return left.next;
    }
};

// 2 pass solution
// General idea -> put all elements >= x at the end
// using a tail pointer
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr)
            return head;
        ListNode *tail = head;
        int count = 0;

        // make tail point at the last node
        // and count the number of nodes which have to be shifted
        while (tail->next != nullptr)
        {
            if (tail->val >= x)
                ++count;
            tail = tail->next;
        }

        if (tail->val >= x)
            ++count; // checking last element

        // traverse from the start
        // if p->val >= x, move it to the end
        ListNode *p = head, *q = nullptr;
        while (count != 0)
        {
            if (p->val >= x)
            {
                // attach the node at tail
                tail->next = p;
                tail = tail->next;

                // remove node connections at p
                if (q == nullptr)
                {
                    head = head->next;
                    p = head;
                }
                else
                {
                    q->next = p->next;
                    p = q->next;
                }

                tail->next = nullptr;
                --count;
            }
            else
            {
                q = p;
                p = p->next;
            }
        }

        return head;
    }
};