/*

solve() can return 1 of 3 values

0 -> denotes that returning node has a camera
1 -> denotes that the returning node is already covered
-1 -> denotes that the returning node needs a cam

*/

class Solution
{
    int cams;

    int solve(TreeNode *root)
    {
        if (!root)
            return 1;

        int _left = solve(root->left);
        int _right = solve(root->right);

        if (_left == -1 || _right == -1)
        {
            cams++;
            return 0;
        }

        if (_left == 0 || _right == 0)
        {
            return 1;
        }

        return -1;
    }

public:
    int minCameraCover(TreeNode *root)
    {
        cams = 0;
        if (solve(root) == -1)
            cams++;
        return cams;
    }
};