/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    TreeNode *toBST(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;

        TreeNode *head = new TreeNode(nums[mid]);
        head->left = toBST(nums, start, mid - 1);
        head->right = toBST(nums, mid + 1, end);
        return head;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return toBST(nums, 0, nums.size() - 1);
    }
};