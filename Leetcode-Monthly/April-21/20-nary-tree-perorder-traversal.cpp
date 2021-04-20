/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{

    void traverse(Node *root, vector<int> &ans)
    {
        if (!root)
            return;

        ans.push_back(root->val);

        for (auto c : root->children)
        {
            traverse(c, ans);
        }
    }

public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};