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
        TreeNode* build(int pre_start, int pre_end, int in_start, int in_end, vector<int> &preorder, vector<int> &inorder, map< int, int> &mp)
        {
            if (pre_start > pre_end || in_start > in_end)
                return NULL;
            TreeNode *root = new TreeNode(preorder[pre_start]);
            int pos = mp[preorder[pre_start]];
            int diff = pos - in_start;
            root->left = build(pre_start + 1, pre_start + diff, in_start, pos - 1, preorder, inorder, mp);
            root->right = build(pre_start + diff + 1, pre_end, pos + 1, in_end, preorder, inorder, mp);
            return root;
        }
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return build(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder, mp);
    }
};