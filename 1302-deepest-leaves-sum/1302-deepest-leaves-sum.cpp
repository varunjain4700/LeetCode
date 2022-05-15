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
        int deepestLeavesSum(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);
            int ans = 0;
            while (!q.empty())
            {
                int sz = q.size();
                ans = 0;
                while (sz--)
                {
                    TreeNode *temp = q.front();
                    ans += temp->val;
                    q.pop();
                    if (temp->left)
                        q.push(temp->left);
                    if (temp->right)
                        q.push(temp->right);
                }
            }
            return ans;
        }
};