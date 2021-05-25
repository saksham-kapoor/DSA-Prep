
// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    // stack will point to inorder predecessor at each point
    void fillStack(Node *curr, stack<Node *> &st)
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->right;
        }
    }

public:
    int kthLargest(Node *root, int K)
    {
        stack<Node *> st;
        fillStack(root, st);

        while (K-- != 1)
        {
            Node *res = st.top();
            st.pop();

            fillStack(res->left, st);
        }

        return st.top()->data;
    }
};