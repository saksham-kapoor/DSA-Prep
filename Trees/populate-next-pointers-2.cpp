class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *head = root, *temp = nullptr;
        Node dummy(0);

        while (head)
        {
            temp = &dummy;

            for (auto h = head; h; h = h->next)
            {
                if (h->left)
                {
                    temp = temp->next = h->left;
                }
                if (h->right)
                {
                    temp = temp->next = h->right;
                }
            }

            head = dummy.next;
            dummy.next = nullptr;
        }

        return root;
    }
};

// bfs solution
// O(N) time, O(N) space
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;

        queue<Node *> q;
        q.push(root);

        while (q.size())
        {
            int size = q.size();
            Node dummy(0);
            Node *temp = &dummy;

            while (size)
            {
                Node *node = q.front();
                q.pop();
                --size;

                temp->next = node;
                temp = temp->next;

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};