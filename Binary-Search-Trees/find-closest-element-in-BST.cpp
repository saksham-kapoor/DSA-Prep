// https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1

class Solution
{
public:
    //Function to find the least absolute difference between any node
    //value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        if (!root)
            return K;

        if (K < root->data)
            return min(root->data - K, minDiff(root->left, K));
        if (K > root->data)
            return min(K - root->data, minDiff(root->right, K));

        return 0;
    }
};