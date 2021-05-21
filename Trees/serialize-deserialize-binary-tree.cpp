/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res = "";

        if (!root)
            return res;

        // int total_nodes = 1;
        queue<TreeNode *> q;
        q.push(root);
        res += to_string(root->val) + " ";

        while (q.size())
        {
            TreeNode *k = q.front();
            q.pop();

            if (k->left)
            {
                res += to_string(k->left->val) + " ";
                q.push(k->left);
                // ++total_nodes;
            }
            else
                res += "n ";

            if (k->right)
            {
                res += to_string(k->right->val) + " ";
                q.push(k->right);
                // ++total_nodes;
            }
            else
                res += "n ";
        }

        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
            return nullptr;

        stringstream ss(data);

        string c;
        ss >> c;
        TreeNode *root = new TreeNode(stoi(c));
        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            TreeNode *node = q.front();
            q.pop();

            ss >> c;
            if (c == "n")
                node->left = nullptr;
            else
            {
                node->left = new TreeNode(stoi(c));
                q.push(node->left);
            }

            ss >> c;
            if (c == "n")
                node->right = nullptr;
            else
            {
                node->right = new TreeNode(stoi(c));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));