/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int widthOfBinaryTree(TreeNode *root)
        {
            queue<pair<TreeNode*, long long>> q;
            q.push({ root,
                1 });
            long long ans = 0;
            while (!q.empty())
            {
                long long minm = 1e15, maxm = -1e15;
                int sz = q.size();
                long long start = q.front().second - 1;
                while (sz--)
                {
                    pair<TreeNode*, long long > p = q.front();
                    q.pop();
                    TreeNode *node = p.first;
                    long long x = p.second;
                    minm = min(minm, x);
                    maxm = max(maxm, x);
                    if (node->left)
                        q.push({ node->left,
                            2 *x - start });
                    if (node->right)
                        q.push({ node->right,
                            2 *x + 1 - start });
                }
                ans = max(ans, maxm - minm + 1);
            }
            return ans;
        }
};