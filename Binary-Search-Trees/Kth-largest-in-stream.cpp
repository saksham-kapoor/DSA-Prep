struct Node
{
    int val;
    int num; // num nodes in tree where selected node is parent
    Node *left;
    Node *right;
    Node()
    {
        val = 0;
        num = 1;
        left = right = nullptr;
    }
    Node(int v)
    {
        val = v;
        num = 1;
        left = right = nullptr;
    }
};

class KthLargest
{
    int k;
    Node *root;

    Node *insert(Node *root, int &val)
    {
        if (!root)
            return new Node(val);

        root->num++;

        if (val <= root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }

    int find(Node *root, int kth)
    {
        // base case
        if (!root->right)
        {
            if (kth == 1)
                return root->val;
            return find(root->left, kth - 1);
        }

        if (kth <= root->right->num)
            return find(root->right, kth);

        if (kth == root->right->num + 1)
            return root->val;

        return find(root->left, kth - root->right->num - 1);
    }

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        root = nullptr;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!root)
                root = insert(root, nums[i]);
            else
                insert(root, nums[i]);
        }
    }

    int add(int val)
    {
        if (!root)
            root = insert(root, val);
        else
            insert(root, val);

        // find kth largest
        return find(root, k);
    }
};