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
        bool isSame(TreeNode *root, TreeNode *SubRoot)
        {
            if (!root && !SubRoot)
                return true;
            if (!root || !SubRoot)
                return false;
            if (root->val == SubRoot->val)
                return isSame(root->left, SubRoot->left) &isSame(root->right, SubRoot->right);
            return false;
        }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;
        if (isSame(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);
    }
};