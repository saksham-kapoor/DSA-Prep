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

// AVL TREE -> HEIGHT BALANCED BST
// Balance factor -> height(left) - height(right) = {-1, 0, 1}
// if BF = -2 or 2 -> perform rotations
/*

  (2)      3
  (1)     2
  (0)    1
  
  if(bf == 2 || bf of l.child == 1) -> means LL imbalance -> R rotation
  
  RR imbalance -> L rotation
  LR imbalance -> LR rotation
  RL imbalance -> RL rotation

*/
// WRONG INTUITION!!!! THE LIST IS SORTED THEREFORE THIS IS NOT THE CORRECT APPROACH
// CHECK LEETCODE #108 FOR INTUITION

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return toBST(head, nullptr);
    }

private:
    TreeNode *toBST(ListNode *head, ListNode *tail)
    {
        if (head == tail)
            return nullptr;

        ListNode *slow = head, *fast = head;

        while (fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *node = new TreeNode(slow->val);
        node->left = toBST(head, slow);
        node->right = toBST(slow->next, tail);
        return node;
    }
};