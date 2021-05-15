// RECURSIVE SOLUTION
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;

        if (root->left)
        {
            root->left->next = root->right;

            if (root->next)
                root->right->next = root->next->left;

            connect(root->left);
            connect(root->right);
        }

        return root;
    }
};

// ITERATIVE SOLUTION!
class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *p = root;
        Node *curr = nullptr;

        while (p && p->left)
        {
            curr = p;

            while (curr)
            {
                curr->left->next = curr->right;

                if (curr->next)
                    curr->right->next = curr->next->left;
                curr = curr->next;
            }

            p = p->left;
        }

        return root;
    }
};