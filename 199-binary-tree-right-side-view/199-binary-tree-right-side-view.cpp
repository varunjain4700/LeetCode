/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> rightSideView(TreeNode *root)
        {
            if (!root)
                return {};
            vector<int> res;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                int sz = q.size();
                while (sz--)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    if (sz == 0)
                        res.push_back(node->val);
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
            }
            return res;
        }
};