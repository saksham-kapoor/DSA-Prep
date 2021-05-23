class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            // 0 or 1 child
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;

            // has 2 children
            TreeNode *newRoot = root->right, *par = nullptr;
            while (newRoot->left)
            {
                par = newRoot;
                newRoot = newRoot->left;
            }

            root->val = newRoot->val; // inorder_successor

            if (!par)
            {
                root->right = newRoot->right;
            }
            else
            {
                par->left = newRoot->right;
            }

            delete (newRoot);
        }

        return root;
    }
};