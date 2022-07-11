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
        void dfs(TreeNode *root, int lvl, vector<int> &res)
        {
            if (!root)
                return;
            if (lvl == res.size())
                res.push_back(root->val);
            dfs(root->right, lvl + 1, res);
            dfs(root->left, lvl + 1, res);
        }
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;
        dfs(root, 0, res);
        return res;
       	// queue<TreeNode*> q;
       	// q.push(root);
       	// while (!q.empty())
       	// {
       	//     int sz = q.size();
       	//     for (int i = 0; i < sz; i++)
       	//     {
       	//         TreeNode *node = q.front();
       	//         q.pop();
       	//         if (i == sz - 1)
       	//             res.push_back(node->val);
       	//         if (node->left)
       	//             q.push(node->left);
       	//         if (node->right)
       	//             q.push(node->right);
       	//     }
       	// }
       	// return res;
    }
};