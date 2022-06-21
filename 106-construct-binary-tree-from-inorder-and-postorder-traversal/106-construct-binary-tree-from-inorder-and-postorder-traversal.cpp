/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* build(vector<int> &inorder, vector<int> &postorder, int post_start, int post_end, int in_start, int in_end, map< int, int> &mp)
        {
            if (in_start > in_end || post_start > post_end)
                return NULL;
            TreeNode *root = new TreeNode(postorder[post_end]);
            int pos = mp[root->val];
            int diff = pos - in_start;
            root->left = build(inorder, postorder, post_start, post_start + diff - 1, in_start, pos - 1, mp);
            root->right = build(inorder, postorder, post_start + diff, post_end - 1, pos + 1, in_end, mp);
            return root;
        }
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, postorder.size() - 1, 0, inorder.size(), mp);
    }
};